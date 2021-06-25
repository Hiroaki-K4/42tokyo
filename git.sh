#!/bin/bash
echo $*
git add .
git commit -m "$1"
git push origin main