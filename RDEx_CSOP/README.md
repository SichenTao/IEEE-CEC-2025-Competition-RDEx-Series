# 🥇 RDEx-CSOP

![IEEE CEC 2025](https://img.shields.io/badge/IEEE%20CEC%202025-Rank%201%20U--score-gold)
![Track](https://img.shields.io/badge/Track-BC--CSOPs-green)
![Language](https://img.shields.io/badge/Language-C%2B%2B%20%2B%20Python-lightgrey)

<p align="center">
  <strong>English</strong> |
  <a href="README.zh-CN.md">中文</a> |
  <a href="README.ja.md">日本語</a>
</p>

**RDEx-CSOP is the CEC 2025 Rank 1 U-score entry for bound-constrained constrained single-objective optimization in the RDEx research line.**

This repository provides a clean open-source package in the same layout style as the RDE26 competition repositories.

## 🥇 Result

| Item | Description |
| --- | --- |
| Achievement | Rank 1 U-score |
| Track | CEC 2025 BC-CSOPs |
| Benchmark | 28 CEC 2017 constrained real-parameter optimization problems |
| Runs | 25 independent runs per problem |
| Budget | 20000 x D function evaluations |
| Total score | 53680.5 |
| Paper | [arXiv:2603.27090](https://arxiv.org/abs/2603.27090) |

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
| `code/rdex-csop/main.py` | Track-specific run entry |
| `code/rdex-csop/RDEx.cpp` | Final algorithm source |
| `code/rdex-csop/cec17_test_COP.cpp` | Benchmark evaluator |
| `code/rdex-csop/inputData/` | Required benchmark input data |

## Requirements

- Python 3
- C++ compiler with C++11 support

## Quick Start

```bash
python3 code/rdex-csop/main.py
```

Generated outputs are written under `code/rdex-csop/outputs/`.

## Citation

Sichen Tao, Yifei Yang, Ruihan Zhao, Kaiyu Wang, Sicheng Liu, and Shangce Gao, "RDEx-CSOP: Feasibility-Aware Reconstructed Differential Evolution with Adaptive epsilon-Constraint Ranking," arXiv:2603.27090, 2026.

```bibtex
@misc{tao2026rdexcsop,
  title = {RDEx-CSOP: Feasibility-Aware Reconstructed Differential Evolution with Adaptive epsilon-Constraint Ranking},
  author = {Tao, Sichen and Yang, Yifei and Zhao, Ruihan and Wang, Kaiyu and Liu, Sicheng and Gao, Shangce},
  year = {2026},
  eprint = {2603.27090},
  archivePrefix = {arXiv},
  primaryClass = {cs.NE},
  doi = {10.48550/arXiv.2603.27090}
}
```
