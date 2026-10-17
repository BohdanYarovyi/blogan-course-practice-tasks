#!/bin/bash

LIB_DIR="$ZED_WORKTREE_ROOT/self-study/mylib"

for task_file in \
    "$ZED_WORKTREE_ROOT"/Homework-*/Task-*/main.cpp \
    "$ZED_WORKTREE_ROOT"/self-study/*/main.cpp; do

    [ -f "$task_file" ] || continue

    task_dir=$(dirname "$task_file")
    rel_path="${task_dir#"$ZED_WORKTREE_ROOT"/}"
    rel_lower=$(echo "$rel_path" | tr '[:upper:]' '[:lower:]')

    out_dir="$ZED_WORKTREE_ROOT/zed-compiled/$rel_lower"
    app="$out_dir/app"

    mkdir -p "$out_dir"

    rebuild=false

    if [ ! -f "$app" ]; then
        rebuild=true
    else
        for source in "$task_dir"/*.cpp "$task_dir"/*.h "$task_dir"/*.hpp \
                      "$LIB_DIR"/*.cpp "$LIB_DIR"/*.hpp; do
            if [ -f "$source" ] && [ "$source" -nt "$app" ]; then
                rebuild=true
                break
            fi
        done
    fi

    [ "$rebuild" = true ] || continue

    echo "Building $rel_path..."

    sources=("$task_dir"/*.cpp "$LIB_DIR"/*.cpp)

    g++ -std=c++20 -g -I"$LIB_DIR" "${sources[@]}" -o "$app" \
        && echo "OK: $rel_path" \
        || echo "FAIL: $rel_path"
done
echo
echo "--- Build was successfully finished."
