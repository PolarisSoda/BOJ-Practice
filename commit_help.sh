#For the VS Code Commit.
#Use sh commit_help.sh (number)

PN=$(find -name *"$1"*)
git add "$PN"
git commit -m "Updated $1"
git push -u origin main