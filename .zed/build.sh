#!/bin/bash

for task_file in "$ZED_WORKTREE_ROOT"/Homework-*/Task-*/main.cpp; do
    homework=$(basename "$(dirname "$(dirname "$task_file")")")
    task=$(basename "$(dirname "$task_file")")
    task_dir=$(dirname "$task_file")

    homework_lower=$(echo "$homework" | tr '[:upper:]' '[:lower:]')
    task_lower=$(echo "$task" | tr '[:upper:]' '[:lower:]')

    out_dir="$ZED_WORKTREE_ROOT/zed-compiled/$homework_lower/$task_lower"
    app="$out_dir/app"

    mkdir -p "$out_dir"

    # Перевіряємо, чи app новіший за ВСІ .cpp файли в Task-#
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

    if [ "$rebuild" = false ]; then
        echo "SKIP: $homework/$task"
        continue
    fi

    echo "Building $homework/$task..."

    # Збираємо main.cpp + всі інші .cpp у Task-#
    sources=("$task_dir"/*.cpp)

    g++ -std=c++20 -g "${sources[@]}" -o "$app" \
        && echo "OK: $homework/$task" \
        || echo "FAIL: $homework/$task"
done
