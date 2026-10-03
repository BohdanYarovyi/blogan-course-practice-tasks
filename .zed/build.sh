#!/bin/bash

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
        for source in "$task_dir"/*.cpp; do
            if [ "$source" -nt "$app" ]; then
                rebuild=true
                break
            fi
        done
    fi

    [ "$rebuild" = true ] || continue

    echo "Building $rel_path..."

    sources=("$task_dir"/*.cpp)

    g++ -std=c++20 -g "${sources[@]}" -o "$app" \
        && echo "OK: $rel_path" \
        || echo "FAIL: $rel_path"
done
echo
echo "--- Build was successfuly finished."
