# Summations

**while** and **for** loops running time can be express as the **sum** of the times spent on each execution of the body of the loop

A.1 Basic formulas involving summations
A.2 Useful techniques for bounding summations

## A.1 Summations formulas and properties
Given a sequence $a_{\scriptstyle 1}, a_{\scriptstyle 2}, ... a_{\scriptstyle n}$, $n \in \mathbb{Z}^{+}$

The value of a **finite** series:
$S = a_{\scriptstyle 1} + a_{\scriptstyle 2} + ... a_{\scriptstyle n} = \sum_{k=1}^{n}a_{\scriptstyle k}$

- If $n = 0$ => $S = 0$
- S is always [well-defined](https://en.wikipedia.org/wiki/Well-defined_expression).
- The sum of these numbers will always be the same, regardless of the order in which they are added together.

<hr>

Given an **infinite sequence** $a_{\scriptstyle 1}, a_{\scriptstyle 2}, ... $

The value of an **infinite** series:
$S = a_{\scriptstyle 1} + a_{\scriptstyle 2} + ... = \sum_{k=1}^{\infty}a_{\scriptstyle k}$
which means $\lim _{n \to \infty}\sum_{k=1}^{n}a_{\scriptstyle k}$

- If the limit does not exist, the series **diverges**.
- Otherwise, it **converges**.

### Geometric series
For real $x \neq 1$, the summation
$$
\begin{align*}
S_{\scriptstyle n}=\sum_{k=0}^{n}x^k = 1 + x + x^2 + ... + x^n
\end{align*}
$$
is a **geometric series** and has the value
$$
\begin{align*}
S_{\scriptstyle n}=\sum_{k=0}^{n}x^k = \sum_{}
\end{align*}
$$