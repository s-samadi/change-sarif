import json
import argparse


def main():
    parser = argparse.ArgumentParser(
        prog='change-sarif'
    )
    parser.add_argument(
        '--inputpath',
        help='Path to the input SARIF file',
        required=True
    )
    parser.add_argument(
        '--outputpath',
        help='Path to the output SARIF file',
        required=True
    )
    parser.add_argument(
        '--ruleid',
        help='Input ruleid (pipe delimiter seperated)',
        required=False
    )
    args = parser.parse_args()
    changesarif(args)


def changesarif(args):

    severity = 'error'

    # Debug information
    print('The severity to be updated to: ' + severity)
    print('The input path provided: ' + args.inputpath)
    print('The output path the file will be written to: ' + args.outputpath)

    # Opening JSON file
    with open(args.inputpath, 'r') as f:

        # returns JSON object as
        # a dictionary
        sarif = json.load(f)

        for run in sarif.get('runs', []):
            rules = run.get('tool').get('driver').get('rules')
            for rule in rules:
                id = rule.get('id')
                if args.ruleid == None:
                    print('Updating ' + id + ' to ' + severity)
                    rule['properties']['problem.severity'] = "test"
                    rule['defaultConfiguration']['level'] = "test"
                else:
                    ruleids = args.ruleid.split('|')
                    for ruleid in ruleids:
                        if(ruleid == id):
                            print('Updating ' + ruleid + ' to ' + severity)
                            rule['properties']['problem.severity'] = "test"
                            rule['defaultConfiguration']['level'] = "test'

    f.close

    with open(args.outputpath, 'w') as f:
        json.dump(sarif, f, indent=2)
    f.close


if __name__ == "__main__":
    main()
