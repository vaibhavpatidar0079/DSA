#!/bin/bash

# 1. Stage all changes (your .gitignore ensures only .cpp files are added)
git add .

# 2. Check if you provided a custom commit message
if [ -z "$1" ]; then
    # No message provided: use auto-generated timestamp
    COMMIT_MSG="Auto-update: $(date +'%Y-%m-%d %H:%M:%S')"
else
    # Message provided: use it
    COMMIT_MSG="$1"
fi

# 3. Commit the changes
git commit -m "$COMMIT_MSG"

# 4. Push to GitHub
git push origin main