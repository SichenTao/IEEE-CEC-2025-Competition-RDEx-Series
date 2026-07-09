# 🥇 IEEE CEC 2025 竞赛 RDEx 系列

![IEEE CEC 2025](https://img.shields.io/badge/IEEE%20CEC%202025-Rank%201%20U--score-gold)
![Series](https://img.shields.io/badge/RDEx-Series-blue)
![Tracks](https://img.shields.io/badge/Tracks-SOP%20%7C%20CSOP%20%7C%20MOP%20%7C%20CMOP-green)

<p align="center">
  <a href="README.md">English</a> |
  <strong>中文</strong> |
  <a href="README.ja.md">日本語</a>
</p>

**RDEx 是 CEC 2025 四个数值优化竞赛赛道的 U-score 第 1 名系列。**

本仓库提供整洁的开源 RDEx 竞赛算法包，覆盖有界约束单目标优化、约束单目标优化、多目标优化和约束多目标优化。

## 🥇 冠军系列

| 结果 | 赛道 | 算法包 | 语言 | 论文 |
| --- | --- | --- | --- | --- |
| 🥇 U-score 第 1 名 (total: 81229.5) | CEC 2025 BC-SOPs | [RDEx_SOP](./RDEx_SOP) | C++ + Python | [arXiv:2603.27089](https://arxiv.org/abs/2603.27089) |
| 🥇 U-score 第 1 名 (total: 53680.5) | CEC 2025 BC-CSOPs | [RDEx_CSOP](./RDEx_CSOP) | C++ + Python | [arXiv:2603.27090](https://arxiv.org/abs/2603.27090) |
| 🥇 U-score 第 1 名 (total: 36343.5) | CEC 2025 BC-MOPs | [RDEx_MOP](./RDEx_MOP) | MATLAB + Python | [arXiv:2603.27092](https://arxiv.org/abs/2603.27092) |
| 🥇 U-score 第 1 名 (total: 58456.0) | CEC 2025 BC-CMOPs | [RDEx_CMOP](./RDEx_CMOP) | MATLAB + Python | [arXiv:2604.03708](https://arxiv.org/abs/2604.03708) |

## 🔗 RDE 研究线

| 年份 | 结果 | 赛道 | 仓库 | 论文 |
| --- | --- | --- | --- | --- |
| 2024 | 🥈 亚军奖 | IEEE CEC 2024 BC-SOPs | [RDE](https://github.com/SichenTao/IEEE-WCCI-CEC-2024-Competition-RDE) | [arXiv:2404.16280](https://arxiv.org/abs/2404.16280) |
| 2025 | 🥇 U-score 第 1 名 | IEEE CEC 2025 RDEx 系列 | [RDEx Series](https://github.com/SichenTao/IEEE-CEC-2025-Competition-RDEx-Series) | [SOP](https://arxiv.org/abs/2603.27089), [CSOP](https://arxiv.org/abs/2603.27090), [MOP](https://arxiv.org/abs/2603.27092), [CMOP](https://arxiv.org/abs/2604.03708) |
| 2026 | 🏆 冠军 / 第 1 名 | IEEE WCCI 2026 / IEEE CEC 2026 RDE26 系列 | [SOP](https://github.com/SichenTao/RDE26-SOP), [CSOP](https://github.com/SichenTao/RDE26-CSOP), [MOP](https://github.com/SichenTao/RDE26-MOP), [CMOP](https://github.com/SichenTao/RDE26-CMOP) | 竞赛公开版本 |

## 仓库结构

| 路径 | 说明 |
| --- | --- |
| `RDEx_SOP/` | 有界约束单目标优化算法包 |
| `RDEx_CSOP/` | 有界约束的约束单目标优化算法包 |
| `RDEx_MOP/` | 有界约束多目标优化算法包 |
| `RDEx_CMOP/` | 有界约束的约束多目标优化算法包 |

每个算法包都包含最终算法源代码、基准材料、赛道专用入口和独立 README。

## 团队

Sichen Tao, Yifei Yang, Ruihan Zhao, Kaiyu Wang, Sicheng Liu, and Shangce Gao.

## 引用

```bibtex
@misc{tao2024efficient,
  title = {An Efficient Reconstructed Differential Evolution Variant by Some of the Current State-of-the-art Strategies for Solving Single Objective Bound Constrained Problems},
  author = {Tao, Sichen and Zhao, Ruihan and Wang, Kaiyu and Gao, Shangce},
  year = {2024},
  eprint = {2404.16280},
  archivePrefix = {arXiv},
  primaryClass = {cs.NE},
  doi = {10.48550/arXiv.2404.16280}
}

@misc{tao2026rdexsop,
  title = {RDEx-SOP: Exploitation-Biased Reconstructed Differential Evolution for Fixed-Budget Bound-Constrained Single-Objective Optimization},
  author = {Tao, Sichen and Yang, Yifei and Zhao, Ruihan and Wang, Kaiyu and Liu, Sicheng and Gao, Shangce},
  year = {2026},
  eprint = {2603.27089},
  archivePrefix = {arXiv},
  primaryClass = {cs.NE},
  doi = {10.48550/arXiv.2603.27089}
}

@misc{tao2026rdexcsop,
  title = {RDEx-CSOP: Feasibility-Aware Reconstructed Differential Evolution with Adaptive epsilon-Constraint Ranking},
  author = {Tao, Sichen and Yang, Yifei and Zhao, Ruihan and Wang, Kaiyu and Liu, Sicheng and Gao, Shangce},
  year = {2026},
  eprint = {2603.27090},
  archivePrefix = {arXiv},
  primaryClass = {cs.NE},
  doi = {10.48550/arXiv.2603.27090}
}

@misc{tao2026rdexmop,
  title = {RDEx-MOP: Indicator-Guided Reconstructed Differential Evolution for Fixed-Budget Multiobjective Optimization},
  author = {Tao, Sichen and Yang, Yifei and Zhao, Ruihan and Wang, Kaiyu and Liu, Sicheng and Gao, Shangce},
  year = {2026},
  eprint = {2603.27092},
  archivePrefix = {arXiv},
  primaryClass = {cs.NE},
  doi = {10.48550/arXiv.2603.27092}
}

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
