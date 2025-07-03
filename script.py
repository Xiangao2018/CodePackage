# /usr/bin/env python3

import os
import yaml

def build_structure(base_path, relative_path=""):
    items = []
    full_path = os.path.join(base_path, relative_path)
    entries = sorted(os.listdir(full_path))

    for entry in entries:
        entry_path = os.path.join(full_path, entry)
        rel_entry_path = os.path.join(relative_path, entry)

        if os.path.isdir(entry_path):
            sub_items = build_structure(base_path, rel_entry_path)
            if sub_items:
                items.append({entry: sub_items})
        elif entry.endswith(".md"):
            display_name = entry.replace(".md", "")
            yaml_path = os.path.join(relative_path, entry).replace("\\", "/")
            items.append({display_name: yaml_path})
    return items

# 指定你想遍历的目录
start_dir = "docs/设计模式"

# 获取目录名作为顶层 key，比如“设计模式”
root_key = os.path.basename(start_dir)
structure = {root_key: build_structure(start_dir)}

# # 输出为 YAML（更漂亮的格式）
print(yaml.dump(structure, allow_unicode=True, sort_keys=False, indent=2))

