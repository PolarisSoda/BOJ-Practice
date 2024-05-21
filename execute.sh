#For the VS Code Execution.
#Use sh execute.sh (number)

PN=$(find -name *"$1"*)
g++ "$PN" -std=c++17 -o t && ./t && rm t