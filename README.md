# change-sarif
This action takes a SARIF file and one or more Rule Id's (pipe seperated) and updates those rules to error severity. 
The parameters it expects are: 
- inputpath: The path of the input SARIF file to be updated 
- outputpath: The path of the output SARIF file to be written to 
- ruleid: The Id of the Rule(s) to be updated, pipe seperated (e.g. rule1 | rule2 )  

# Example
```yaml 
name: "CodeQL"
on:
  push:
    branches: [ main ]
  pull_request:
    # The branches below must be a subset of the branches above
    branches: [ main ]
  schedule:
    - cron: '34 22 * * 4'

jobs:
  analyze:
    name: Analyze
    runs-on: ubuntu-latest

    strategy:
      fail-fast: false
      matrix:
        language: [ 'cpp' ]
  
    steps:
    - name: Checkout repository
      uses: actions/checkout@v2

    # Initializes the CodeQL tools for scanning.
    - name: Initialize CodeQL
      uses: github/codeql-action/init@v1
      with:
        languages: ${{ matrix.language }}
     
    - name: Build
      run: |
       c-test-proj/Makefile
        

    - name: Perform CodeQL Analysis
      uses: github/codeql-action/analyze@v1
      with:
        upload: False
        output: sarif-results
      
    - name: Set up Python 
      uses: actions/setup-python@v2
      
    - name: change-sarif
      uses: s-samadi/change-sarif@main
      with:
        ruleid: cpp/tainted-format-string
        inputpath: sarif-results/cpp-builtin.sarif
        outputpath: sarif-results/cpp-builtin.sarif
      

    - name: Upload SARIF
      uses: github/codeql-action/upload-sarif@v1
      with:
        sarif_file: sarif-results/cpp-builtin.sarif

    - name: Upload loc as a Build Artifact
      uses: actions/upload-artifact@v2.2.0
      with:
        name: sarif-results
        path: sarif-results
        retention-days: 1
