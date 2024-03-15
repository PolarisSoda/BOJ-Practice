#For the VS Code Execution.
#Use sh execute.sh (number)

PN=$(find -name *"$1"*)
git add "$PN"
git commit -m "Updated $1"
git push -u origin main