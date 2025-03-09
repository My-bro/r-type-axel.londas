#!/bin/bash

# Define the base path to the CMakeLists.txt file
BASE_PATH="build/cpm_cache/sfml/*/src/SFML/Graphics/CMakeLists.txt"

# Use sed to delete lines containing ${SRCROOT}/Font.cpp and ${INCROOT}/Font.hpp
for file in $BASE_PATH; do
    if [ -f "$file" ]; then
        sed -i '' '/${SRCROOT}\/Font.cpp/d' "$file"
        sed -i '' '/${INCROOT}\/Font.hpp/d' "$file"
        echo "Deleted lines containing \${SRCROOT}/Font.cpp and \${INCROOT}/Font.hpp from $file"
    else
        echo "File not found: $file"
    fi
done