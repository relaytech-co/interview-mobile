#!/bin/bash

# This script runs flutter tests for a given directory (defaults to the current directory)
# It includes only specific files in the coverage report and opens the report in a new window once complete.
#
# To run in the main project:
# ./tool/coverage.sh
#
# To run in another directory:
# ./tool/coverage.sh ./path/to/other/project

set -e

PROJECT_PATH="${1:-.}"
PROJECT_COVERAGE=./coverage/lcov.info

cd ${PROJECT_PATH}

# Clean previous coverage data
rm -rf coverage
flutter --version
flutter test --coverage

# Include only files that match the specified patterns
lcov --extract ${PROJECT_COVERAGE} -o ${PROJECT_COVERAGE} '**/*.dart'

# Dont include generated files
lcov --remove ${PROJECT_COVERAGE} '**/*.g.dart' -o ${PROJECT_COVERAGE}

# Generate HTML report from the filtered coverage data
genhtml ${PROJECT_COVERAGE} -o coverage | tee ./coverage/output.txt

# Check if the coverage is 100%
COV_LINE=$(tail -2 ./coverage/output.txt | head -1)
SUB='100.0%'

if [[ "$COV_LINE" == *"$SUB"* ]]; then
    echo "The coverage is 100%"
else
    echo "Coverage is below 100%! Check the report to see which lines are not covered."
    echo $COV_LINE
    open ./coverage/index.html
fi


#!/bin/bash

# set -e

# PROJECT_PATH="${1:-.}"
# PROJECT_COVERAGE=./coverage/lcov.info

# cd ${PROJECT_PATH}

# rm -rf coverage
# flutter --version
# flutter test --coverage

# if [ ! -f "${PROJECT_COVERAGE}" ]; then
#   echo "Error: Coverage file ${PROJECT_COVERAGE} not found!"
#   exit 1
# fi

# lcov --extract  ${PROJECT_COVERAGE} -o ${PROJECT_COVERAGE} \ 
#     '**/*_state.dart' \
#     '**/*_provider.dart' \
#     '**/*_service.dart' \
#     '**/*_controller.dart' \
#     '**/*_extension.dart' 

# genhtml ${PROJECT_COVERAGE} -o coverage | tee ./coverage/output.txt

# COV_LINE=$(tail -2 ./coverage/output.txt | head -1)
# SUB='100.0%'

# if [[ "$COV_LINE" == *"$SUB"* ]]; then
#     echo "The coverage is 100%"
# else
#     echo "Coverage is below 100%! Check the report to see which lines are not covered."
#     echo $COV_LINE
#     open ./coverage/index.html
# fi