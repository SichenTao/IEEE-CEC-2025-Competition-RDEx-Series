#!/usr/bin/env python3
from __future__ import annotations

import argparse
import shutil
import subprocess
from pathlib import Path


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(description="Run the RDEx-CMOP MATLAB entry.")
    parser.add_argument("--matlab", default="matlab")
    parser.add_argument("--check", action="store_true")
    return parser.parse_args()


def main() -> int:
    args = parse_args()
    root = Path(__file__).resolve().parent
    executable = shutil.which(args.matlab)
    if executable is None:
        raise SystemExit(f"MATLAB executable not found: {args.matlab}")
    if args.check:
        print(executable)
        return 0
    subprocess.run([executable, "-batch", f"run('{(root / 'main.m').as_posix()}')"], check=True)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
