# 🥇 RDEx-MOP

![IEEE CEC 2025](https://img.shields.io/badge/IEEE%20CEC%202025-Rank%201%20U--score-gold)
![Track](https://img.shields.io/badge/Track-BC--MOPs-green)
![Language](https://img.shields.io/badge/Language-MATLAB-lightgrey)

**RDEx-MOP is the CEC 2025 Rank 1 U-score entry for bound-constrained multi-objective optimization in the RDEx research line.**

This repository provides a clean open-source package in the same layout style as the RDE26 competition repositories.

## 🥇 Result

| Item | Description |
| --- | --- |
| Achievement | Rank 1 U-score |
| Track | CEC 2025 BC-MOPs |
| Benchmark | 10 multi-objective optimization problems |
| Runs | 30 independent runs per problem |
| Budget | 100000 function evaluations per problem |
| Total score | 36343.5 |
| Paper | [arXiv:2603.27092](https://arxiv.org/abs/2603.27092) |

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
| `code/rdex-mop/main.py` | Track-specific run entry |
| `code/rdex-mop/main.m` | MATLAB run entry |
| `code/rdex-mop/Algorithm/` | Final algorithm source and runtime classes |
| `code/rdex-mop/Metrics/` | Metric functions used by the included MATLAB runtime |

## Requirements

- Python 3
- MATLAB

## Quick Start

```bash
python3 code/rdex-mop/main.py
```

## Citation

Sichen Tao, Yifei Yang, Ruihan Zhao, Kaiyu Wang, Sicheng Liu, and Shangce Gao, "RDEx-MOP: Indicator-Guided Reconstructed Differential Evolution for Fixed-Budget Multiobjective Optimization," arXiv:2603.27092, 2026.

```bibtex
@misc{tao2026rdexmop,
  title = {RDEx-MOP: Indicator-Guided Reconstructed Differential Evolution for Fixed-Budget Multiobjective Optimization},
  author = {Tao, Sichen and Yang, Yifei and Zhao, Ruihan and Wang, Kaiyu and Liu, Sicheng and Gao, Shangce},
  year = {2026},
  eprint = {2603.27092},
  archivePrefix = {arXiv},
  primaryClass = {cs.NE},
  doi = {10.48550/arXiv.2603.27092}
}
```
