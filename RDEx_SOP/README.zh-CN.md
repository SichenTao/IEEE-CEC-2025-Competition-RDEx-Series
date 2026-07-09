# 🥇 RDEx-SOP

![IEEE CEC 2025](https://img.shields.io/badge/IEEE%20CEC%202025-Rank%201%20U--score-gold)
![Track](https://img.shields.io/badge/Track-BC--SOPs-green)
![Language](https://img.shields.io/badge/Language-C%2B%2B%20%2B%20Python-lightgrey)

<p align="center">
  <a href="README.md">English</a> |
  <strong>中文</strong> |
  <a href="README.ja.md">日本語</a>
</p>

**RDEx-SOP 是 RDE 研究线中面向有界约束单目标优化的 CEC 2025 U-score 第 1 名参赛方案。**

本目录按与 RDE26 竞赛仓库一致的结构，提供整洁的开源算法包。

## 🥇 结果

| 项目 | 说明 |
| --- | --- |
| 成绩 | U-score 第 1 名 |
| 赛道 | CEC 2025 BC-SOPs |
| 基准 | 29 个 CEC 2017 实参数值优化问题 |
| 运行次数 | 每个问题 25 次独立运行 |
| 预算 | 10000 x D 次函数评价 |
| 总分 | 81229.5 |
| 论文 | [arXiv:2603.27089](https://arxiv.org/abs/2603.27089) |

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
| `code/rdex-sop/main.py` | 该赛道专用运行入口 |
| `code/rdex-sop/RDEx.cpp` | 最终算法源代码 |
| `code/rdex-sop/cec17_test_func.cpp` | 基准评价器 |
| `code/rdex-sop/input_data/` | 必要的基准输入数据 |

## 运行需求

- Python 3
- C++14 编译器

## 快速开始

```bash
python3 code/rdex-sop/main.py
```

生成结果会写入 `code/rdex-sop/outputs/`。

## 引用

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
