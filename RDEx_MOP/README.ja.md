# 🥇 RDEx-MOP

![IEEE CEC 2025](https://img.shields.io/badge/IEEE%20CEC%202025-Rank%201%20U--score-gold)
![Track](https://img.shields.io/badge/Track-BC--MOPs-green)
![Language](https://img.shields.io/badge/Language-MATLAB-lightgrey)

<p align="center">
  <a href="README.md">English</a> |
  <a href="README.zh-CN.md">中文</a> |
  <strong>日本語</strong>
</p>

**RDEx-MOP は、RDE 研究ラインにおける有界制約多目的最適化向けの CEC 2025 Rank 1 U-score エントリです。**

本ディレクトリは、RDE26 コンペティションリポジトリと同じ構成方針に基づく、整理済みのオープンソースパッケージを提供します。

## 🥇 結果

| 項目 | 説明 |
| --- | --- |
| 成績 | Rank 1 U-score |
| トラック | CEC 2025 BC-MOPs |
| ベンチマーク | 多目的最適化問題 10 問 |
| 実行回数 | 各問題につき 30 回の独立実行 |
| 評価予算 | 各問題につき 100000 回の関数評価 |
| 総スコア | 36343.5 |
| 論文 | [arXiv:2603.27092](https://arxiv.org/abs/2603.27092) |

## 🧭 シリーズナビゲーション

| 結果 | トラック | リポジトリ | 論文 |
| --- | --- | --- | --- |
| 🥇 Rank 1 U-score (total: 81229.5) | CEC 2025 BC-SOPs | [RDEx-SOP](../RDEx_SOP) | [arXiv:2603.27089](https://arxiv.org/abs/2603.27089) |
| 🥇 Rank 1 U-score (total: 53680.5) | CEC 2025 BC-CSOPs | [RDEx-CSOP](../RDEx_CSOP) | [arXiv:2603.27090](https://arxiv.org/abs/2603.27090) |
| 🥇 Rank 1 U-score (total: 36343.5) | CEC 2025 BC-MOPs | [RDEx-MOP](../RDEx_MOP) | [arXiv:2603.27092](https://arxiv.org/abs/2603.27092) |
| 🥇 Rank 1 U-score (total: 58456.0) | CEC 2025 BC-CMOPs | [RDEx-CMOP](../RDEx_CMOP) | [arXiv:2604.03708](https://arxiv.org/abs/2604.03708) |

## 🔗 RDE 研究ライン

| 年 | 結果 | エントリ | リポジトリ | 論文 |
| --- | --- | --- | --- | --- |
| 2024 | 🥈 Runner-Up Award | IEEE CEC 2024 BC-SOPs | [RDE](https://github.com/SichenTao/IEEE-WCCI-CEC-2024-Competition-RDE) | [arXiv:2404.16280](https://arxiv.org/abs/2404.16280) |
| 2025 | 🥇 Rank 1 U-score | IEEE CEC 2025 RDEx シリーズ | [RDEx Series](https://github.com/SichenTao/IEEE-CEC-2025-Competition-RDEx-Series) | [SOP](https://arxiv.org/abs/2603.27089), [CSOP](https://arxiv.org/abs/2603.27090), [MOP](https://arxiv.org/abs/2603.27092), [CMOP](https://arxiv.org/abs/2604.03708) |
| 2026 | 🏆 優勝 / 第 1 位 | IEEE WCCI 2026 / IEEE CEC 2026 RDE26 シリーズ | [SOP](https://github.com/SichenTao/RDE26-SOP), [CSOP](https://github.com/SichenTao/RDE26-CSOP), [MOP](https://github.com/SichenTao/RDE26-MOP), [CMOP](https://github.com/SichenTao/RDE26-CMOP) | コンペティション公開版 |

## チーム

Sichen Tao, Yifei Yang, Ruihan Zhao, Kaiyu Wang, Sicheng Liu, and Shangce Gao.

## リポジトリ構成

| パス | 説明 |
| --- | --- |
| `benchmark/` | 公開ベンチマーク資料 |
| `code/rdex-mop/main.py` | トラック専用の実行エントリ |
| `code/rdex-mop/main.m` | MATLAB 実行エントリ |
| `code/rdex-mop/Algorithm/` | 最終アルゴリズムのソースコードと実行時クラス |
| `code/rdex-mop/Metrics/` | 同梱 MATLAB 実行時で使用される指標関数 |

## 要件

- Python 3
- MATLAB

## クイックスタート

```bash
python3 code/rdex-mop/main.py
```

## 引用

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
