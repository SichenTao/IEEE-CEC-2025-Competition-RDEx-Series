#!/usr/bin/env python3
from __future__ import annotations

import argparse
import shutil
import subprocess
from pathlib import Path


def parse_args() -> argparse.Namespace:
    root = Path(__file__).resolve().parent
    parser = argparse.ArgumentParser(description="Run the RDEx-SOP algorithm.")
    parser.add_argument("--out-dir", type=Path, default=root / "outputs")
    parser.add_argument("--cxx", default="g++")
    parser.add_argument("--compile-only", action="store_true")
    return parser.parse_args()


def build_binary(root: Path, cxx: str) -> Path:
    build = root / "build"
    build.mkdir(parents=True, exist_ok=True)
    binary = build / "rdex_sop"
    subprocess.run(
        [cxx, "-O3", "-std=c++14", "-I", ".", "RDEx.cpp", "-o", str(binary)],
        cwd=str(root),
        check=True,
    )
    return binary


def main() -> int:
    args = parse_args()
    root = Path(__file__).resolve().parent
    binary = build_binary(root, args.cxx)
    if args.compile_only:
        print(binary)
        return 0

    args.out_dir.mkdir(parents=True, exist_ok=True)
    run_binary = args.out_dir / binary.name
    shutil.copy2(binary, run_binary)
    shutil.copytree(root / "input_data", args.out_dir / "input_data", dirs_exist_ok=True)
    subprocess.run([str(run_binary)], cwd=str(args.out_dir), check=True)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
