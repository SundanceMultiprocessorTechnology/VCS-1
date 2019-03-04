#! /bin/bash
echo "# Directory Structure" > directorySctructure.md
echo "\`\`\`" >> directorySctructure.md
tree ../VCS-1 >> directorySctructure.md
echo "\`\`\`" >> directorySctructure.md 
git add *
git commit -m "updates"
git push
