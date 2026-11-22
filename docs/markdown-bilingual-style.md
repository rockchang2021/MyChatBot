# Project Markdown: Bilingual Style | 项目 Markdown 双语规范

## Scope | 适用范围

**Must be bilingual (EN + ZH) | 必须中英对照：**

| Path | EN | ZH |
|------|----|-----|
| `specs/<feature>/**` | Spec Kit feature artifacts | Spec Kit 功能制品 |
| `.specify/memory/constitution.md` | Project constitution | 项目宪法 |
| `README.md` (repository root) | Project entry overview | 仓库总览 |

**Not required bilingual | 不要求双语：**

- `.cursor/skills/**`, `.specify/templates/**` — vendor Spec Kit; **do not edit** | 上游，禁止改
- `docs/hardware.md`, `components/*/README.md`, other ad-hoc notes — optional | 硬件笔记、驱动 README 等可选

**维护说明：** 双语用于团队长期维护 **规格、宪法与仓库入口**。

---

## Format | 格式

- Titles: `# English | 中文` or `## English | 中文`
- Narrative:

```markdown
> **EN:** …
> **ZH | 中文：** …
```

- Code, paths, `CONFIG_*`, APIs, Given/When/Then: keep English; add ZH when needed.

## Agent prompt | 调用 Spec Kit 时附加

```text
Bilingual (EN+ZH) per docs/markdown-bilingual-style.md for specs/*, constitution.md, and root README.md.
Do not edit .cursor/skills or .specify/templates.
```