#For the VS Code Execution.
#Use sh execute.sh (number)

PN=$(find -name *"$1"*)
g++ "$PN" -o t && ./t && rm t