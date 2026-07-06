# 🥇 RDEx-SOP

![IEEE CEC 2025](https://img.shields.io/badge/IEEE%20CEC%202025-Rank%201%20U--score-gold)
![Track](https://img.shields.io/badge/Track-BC--SOPs-green)
![Language](https://img.shields.io/badge/Language-C%2B%2B%20%2B%20Python-lightgrey)

**RDEx-SOP is the CEC 2025 Rank 1 U-score entry for bound-constrained single-objective optimization in the RDEx research line.**

This repository provides a clean open-source package in the same layout style as the RDE26 competition repositories.

## 🥇 Result

| Item | Description |
| --- | --- |
| Achievement | Rank 1 U-score |
| Track | CEC 2025 BC-SOPs |
| Benchmark | 29 CEC 2017 real-parameter numerical optimization problems |
| Runs | 25 independent runs per problem |
| Budget | 10000 x D function evaluations |
| Total score | 81229.5 |
| Paper | [arXiv:2603.27089](https://arxiv.org/abs/2603.27089) |

## 🧭 Series Navigation

| Result | Track | Repository | Paper |
| --- | --- | --- | --- |
| 🥇 Rank 1 U-score (total: 81229.5) | CEC 2025 BC-SOPs | [RDEx-SOP](../RDEx_SOP) | [arXiv:2603.27089](https://arxiv.org/abs/2603.27089) |
| 🥇 Rank 1 U-score (total: 53680.5) | CEC 2025 BC-CSOPs | [RDEx-CSOP](../RDEx_CSOP) | [arXiv:2603.27090](https://arxiv.org/abs/2603.27090) |
| 🥇 Rank 1 U-score (total: 36343.5) | CEC 2025 BC-MOPs | [RDEx-MOP](../RDEx_MOP) | [arXiv:2603.27092](https://arxiv.org/abs/2603.27092) |
| 🥇 Rank 1 U-score (total: 58456.0) | CEC 2025 BC-CMOPs | [RDEx-CMOP](../RDEx_CMOP) | [arXiv:2604.03708](https://arxiv.org/abs/2604.03708) |

## Team

Sichen Tao, Yifei Yang, Ruihan Zhao, Kaiyu Wang, Sicheng Liu, and Shangce Gao.

## Repository Layout

| Path | Description |
| --- | --- |
| `benchmark/` | Public benchmark materials |
| `code/rdex-sop/main.py` | Track-specific run entry |
| `code/rdex-sop/RDEx.cpp` | Final algorithm source |
| `code/rdex-sop/cec17_test_func.cpp` | Benchmark evaluator |
| `code/rdex-sop/input_data/` | Required benchmark input data |

## Requirements

- Python 3
- C++14 compiler

## Quick Start

```bash
python3 code/rdex-sop/main.py
```

Generated outputs are written under `code/rdex-sop/outputs/`.

## Citation

Sichen Tao, Yifei Yang, Ruihan Zhao, Kaiyu Wang, Sicheng Liu, and Shangce Gao, "RDEx-SOP: Exploitation-Biased Reconstructed Differential Evolution for Fixed-Budget Bound-Constrained Single-Objective Optimization," arXiv:2603.27089, 2026.

```bibtex
@misc{tao2026rdexsop,
  title = {RDEx-SOP: Exploitation-Biased Reconstructed Differential Evolution for Fixed-Budget Bound-Constrained Single-Objective Optimization},
  author = {Tao, Sichen and Yang, Yifei and Zhao, Ruihan and Wang, Kaiyu and Liu, Sicheng and Gao, Shangce},
  year = {2026},
  eprint = {2603.27089},
  archivePrefix = {arXiv},
  primaryClass = {cs.NE},
  doi = {10.48550/arXiv.2603.27089}
}
```
