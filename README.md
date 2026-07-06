# 🥇 RDEx Series for IEEE CEC 2025 Competitions

![IEEE CEC 2025](https://img.shields.io/badge/IEEE%20CEC%202025-Rank%201%20U--score-gold)
![Series](https://img.shields.io/badge/RDEx-Series-blue)
![Tracks](https://img.shields.io/badge/Tracks-SOP%20%7C%20CSOP%20%7C%20MOP%20%7C%20CMOP-green)

**RDEx is the CEC 2025 Rank 1 U-score series for four numerical optimization competition tracks.**

This repository provides the clean open-source RDEx competition packages for bound-constrained single-objective, constrained single-objective, multi-objective, and constrained multi-objective optimization.

## 🥇 Champion Series

| Result | Track | Package | Language | Paper |
| --- | --- | --- | --- | --- |
| 🥇 Rank 1 U-score (total: 81229.5) | CEC 2025 BC-SOPs | [RDEx_SOP](./RDEx_SOP) | C++ + Python | [arXiv:2603.27089](https://arxiv.org/abs/2603.27089) |
| 🥇 Rank 1 U-score (total: 53680.5) | CEC 2025 BC-CSOPs | [RDEx_CSOP](./RDEx_CSOP) | C++ + Python | [arXiv:2603.27090](https://arxiv.org/abs/2603.27090) |
| 🥇 Rank 1 U-score (total: 36343.5) | CEC 2025 BC-MOPs | [RDEx_MOP](./RDEx_MOP) | MATLAB + Python | [arXiv:2603.27092](https://arxiv.org/abs/2603.27092) |
| 🥇 Rank 1 U-score (total: 58456.0) | CEC 2025 BC-CMOPs | [RDEx_CMOP](./RDEx_CMOP) | MATLAB + Python | [arXiv:2604.03708](https://arxiv.org/abs/2604.03708) |

## 🔗 RDE Research Line

| Year | Result | Track | Repository | Paper |
| --- | --- | --- | --- | --- |
| 2024 | 🥈 Runner-Up Award | IEEE CEC 2024 BC-SOPs | [RDE](https://github.com/SichenTao/IEEE-WCCI-CEC-2024-Competition-RDE) | [arXiv:2404.16280](https://arxiv.org/abs/2404.16280) |
| 2025 | 🥇 Rank 1 U-score | IEEE CEC 2025 RDEx Series | [RDEx Series](https://github.com/SichenTao/IEEE-CEC-2025-Competition-RDEx-Series) | [SOP](https://arxiv.org/abs/2603.27089), [CSOP](https://arxiv.org/abs/2603.27090), [MOP](https://arxiv.org/abs/2603.27092), [CMOP](https://arxiv.org/abs/2604.03708) |
| 2026 | 🏆 Champion / Rank 1 | IEEE WCCI 2026 / IEEE CEC 2026 RDE26 Series | [SOP](https://github.com/SichenTao/RDE26-SOP), [CSOP](https://github.com/SichenTao/RDE26-CSOP), [MOP](https://github.com/SichenTao/RDE26-MOP), [CMOP](https://github.com/SichenTao/RDE26-CMOP) | Competition release |

## Repository Layout

| Path | Description |
| --- | --- |
| `RDEx_SOP/` | Bound-constrained single-objective optimization package |
| `RDEx_CSOP/` | Bound-constrained constrained single-objective optimization package |
| `RDEx_MOP/` | Bound-constrained multi-objective optimization package |
| `RDEx_CMOP/` | Bound-constrained constrained multi-objective optimization package |

Each package contains the final algorithm source, benchmark materials, a track-specific entry point, and a dedicated README.

## Team

Sichen Tao, Yifei Yang, Ruihan Zhao, Kaiyu Wang, Sicheng Liu, and Shangce Gao.

## Citation

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
