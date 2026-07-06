# 🥇 RDEx-CMOP

![IEEE CEC 2025](https://img.shields.io/badge/IEEE%20CEC%202025-Rank%201%20U--score-gold)
![Track](https://img.shields.io/badge/Track-BC--CMOPs-green)
![Language](https://img.shields.io/badge/Language-MATLAB-lightgrey)

**RDEx-CMOP is the CEC 2025 Rank 1 U-score entry for bound-constrained constrained multi-objective optimization in the RDEx research line.**

This repository provides a clean open-source package in the same layout style as the RDE26 competition repositories.

## 🥇 Result

| Item | Description |
| --- | --- |
| Achievement | Rank 1 U-score |
| Track | CEC 2025 BC-CMOPs |
| Benchmark | 15 scalable decision-space constrained multi-objective optimization problems |
| Runs | 30 independent runs per problem |
| Budget | 200000 function evaluations per problem |
| Total score | 58456.0 |
| Paper | [arXiv:2604.03708](https://arxiv.org/abs/2604.03708) |

## 🧭 Series Navigation

| Result | Track | Repository | Paper |
| --- | --- | --- | --- |
| 🥇 Rank 1 U-score (total: 81229.5) | CEC 2025 BC-SOPs | [RDEx-SOP](../RDEx_SOP) | [arXiv:2603.27089](https://arxiv.org/abs/2603.27089) |
| 🥇 Rank 1 U-score (total: 53680.5) | CEC 2025 BC-CSOPs | [RDEx-CSOP](../RDEx_CSOP) | [arXiv:2603.27090](https://arxiv.org/abs/2603.27090) |
| 🥇 Rank 1 U-score (total: 36343.5) | CEC 2025 BC-MOPs | [RDEx-MOP](../RDEx_MOP) | [arXiv:2603.27092](https://arxiv.org/abs/2603.27092) |
| 🥇 Rank 1 U-score (total: 58456.0) | CEC 2025 BC-CMOPs | [RDEx-CMOP](../RDEx_CMOP) | [arXiv:2604.03708](https://arxiv.org/abs/2604.03708) |

## 🔗 RDE Research Line

| Year | Result | Entry | Repository | Paper |
| --- | --- | --- | --- | --- |
| 2024 | 🥈 Runner-Up Award | IEEE CEC 2024 BC-SOPs | [RDE](https://github.com/SichenTao/IEEE-WCCI-CEC-2024-Competition-RDE) | [arXiv:2404.16280](https://arxiv.org/abs/2404.16280) |
| 2025 | 🥇 Rank 1 U-score | IEEE CEC 2025 RDEx Series | [RDEx Series](https://github.com/SichenTao/IEEE-CEC-2025-Competition-RDEx-Series) | [SOP](https://arxiv.org/abs/2603.27089), [CSOP](https://arxiv.org/abs/2603.27090), [MOP](https://arxiv.org/abs/2603.27092), [CMOP](https://arxiv.org/abs/2604.03708) |
| 2026 | 🏆 Champion / Rank 1 | IEEE WCCI 2026 / IEEE CEC 2026 RDE26 Series | [SOP](https://github.com/SichenTao/RDE26-SOP), [CSOP](https://github.com/SichenTao/RDE26-CSOP), [MOP](https://github.com/SichenTao/RDE26-MOP), [CMOP](https://github.com/SichenTao/RDE26-CMOP) | Competition release |

## Team

Sichen Tao, Yifei Yang, Ruihan Zhao, Kaiyu Wang, Sicheng Liu, and Shangce Gao.

## Repository Layout

| Path | Description |
| --- | --- |
| `benchmark/` | Public benchmark materials |
| `code/rdex-cmop/main.py` | Track-specific run entry |
| `code/rdex-cmop/main.m` | MATLAB run entry |
| `code/rdex-cmop/Algorithm/` | Final algorithm source and runtime classes |
| `code/rdex-cmop/Metrics/` | Metric functions used by the included MATLAB runtime |

## Requirements

- Python 3
- MATLAB

## Quick Start

```bash
python3 code/rdex-cmop/main.py
```

## Citation

Sichen Tao, Yifei Yang, Ruihan Zhao, Kaiyu Wang, Sicheng Liu, and Shangce Gao, "RDEx-CMOP: Feasibility-Aware Indicator-Guided Differential Evolution for Fixed-Budget Constrained Multiobjective Optimization," arXiv:2604.03708, 2026.

```bibtex
@misc{tao2026rdexcmop,
  title = {RDEx-CMOP: Feasibility-Aware Indicator-Guided Differential Evolution for Fixed-Budget Constrained Multiobjective Optimization},
  author = {Tao, Sichen and Yang, Yifei and Zhao, Ruihan and Wang, Kaiyu and Liu, Sicheng and Gao, Shangce},
  year = {2026},
  eprint = {2604.03708},
  archivePrefix = {arXiv},
  primaryClass = {cs.NE},
  doi = {10.48550/arXiv.2604.03708}
}
```
