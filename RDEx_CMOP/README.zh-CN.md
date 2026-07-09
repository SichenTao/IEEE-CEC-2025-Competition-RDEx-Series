# 🥇 RDEx-CMOP

![IEEE CEC 2025](https://img.shields.io/badge/IEEE%20CEC%202025-Rank%201%20U--score-gold)
![Track](https://img.shields.io/badge/Track-BC--CMOPs-green)
![Language](https://img.shields.io/badge/Language-MATLAB-lightgrey)

<p align="center">
  <a href="README.md">English</a> |
  <strong>中文</strong> |
  <a href="README.ja.md">日本語</a>
</p>

**RDEx-CMOP 是 RDE 研究线中面向有界约束的约束多目标优化的 CEC 2025 U-score 第 1 名参赛方案。**

本目录按与 RDE26 竞赛仓库一致的结构，提供整洁的开源算法包。

## 🥇 结果

| 项目 | 说明 |
| --- | --- |
| 成绩 | U-score 第 1 名 |
| 赛道 | CEC 2025 BC-CMOPs |
| 基准 | 15 个可扩展决策空间约束多目标优化问题 |
| 运行次数 | 每个问题 30 次独立运行 |
| 预算 | 每个问题 200000 次函数评价 |
| 总分 | 58456.0 |
| 论文 | [arXiv:2604.03708](https://arxiv.org/abs/2604.03708) |

## 🧭 系列导航

| 结果 | 赛道 | 仓库 | 论文 |
| --- | --- | --- | --- |
| 🥇 U-score 第 1 名 (total: 81229.5) | CEC 2025 BC-SOPs | [RDEx-SOP](../RDEx_SOP) | [arXiv:2603.27089](https://arxiv.org/abs/2603.27089) |
| 🥇 U-score 第 1 名 (total: 53680.5) | CEC 2025 BC-CSOPs | [RDEx-CSOP](../RDEx_CSOP) | [arXiv:2603.27090](https://arxiv.org/abs/2603.27090) |
| 🥇 U-score 第 1 名 (total: 36343.5) | CEC 2025 BC-MOPs | [RDEx-MOP](../RDEx_MOP) | [arXiv:2603.27092](https://arxiv.org/abs/2603.27092) |
| 🥇 U-score 第 1 名 (total: 58456.0) | CEC 2025 BC-CMOPs | [RDEx-CMOP](../RDEx_CMOP) | [arXiv:2604.03708](https://arxiv.org/abs/2604.03708) |

## 🔗 RDE 研究线

| 年份 | 结果 | 参赛项 | 仓库 | 论文 |
| --- | --- | --- | --- | --- |
| 2024 | 🥈 亚军奖 | IEEE CEC 2024 BC-SOPs | [RDE](https://github.com/SichenTao/IEEE-WCCI-CEC-2024-Competition-RDE) | [arXiv:2404.16280](https://arxiv.org/abs/2404.16280) |
| 2025 | 🥇 U-score 第 1 名 | IEEE CEC 2025 RDEx 系列 | [RDEx Series](https://github.com/SichenTao/IEEE-CEC-2025-Competition-RDEx-Series) | [SOP](https://arxiv.org/abs/2603.27089), [CSOP](https://arxiv.org/abs/2603.27090), [MOP](https://arxiv.org/abs/2603.27092), [CMOP](https://arxiv.org/abs/2604.03708) |
| 2026 | 🏆 冠军 / 第 1 名 | IEEE WCCI 2026 / IEEE CEC 2026 RDE26 系列 | [SOP](https://github.com/SichenTao/RDE26-SOP), [CSOP](https://github.com/SichenTao/RDE26-CSOP), [MOP](https://github.com/SichenTao/RDE26-MOP), [CMOP](https://github.com/SichenTao/RDE26-CMOP) | 竞赛公开版本 |

## 团队

Sichen Tao, Yifei Yang, Ruihan Zhao, Kaiyu Wang, Sicheng Liu, and Shangce Gao.

## 仓库结构

| 路径 | 说明 |
| --- | --- |
| `benchmark/` | 公开基准材料 |
| `code/rdex-cmop/main.py` | 该赛道专用运行入口 |
| `code/rdex-cmop/main.m` | MATLAB 运行入口 |
| `code/rdex-cmop/Algorithm/` | 最终算法源代码和运行时类 |
| `code/rdex-cmop/Metrics/` | 内置 MATLAB 运行时使用的指标函数 |

## 运行需求

- Python 3
- MATLAB

## 快速开始

```bash
python3 code/rdex-cmop/main.py
```

## 引用

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
