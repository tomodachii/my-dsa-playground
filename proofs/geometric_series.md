# Proofs for Geometric series formula
Proof for the [geometric formula](../summations.md/#geometric-series)

$$
\begin{equation} \tag{1}
\begin{split}
S_{\scriptstyle n}=\sum_{k=0}^{n}x^k = 1 + x + x^2 + ... + x^n
\end{split}
\end{equation}
$$

Multiplying both sides by $x$ gives

$$
\begin{equation} \tag{2}
\begin{split}
&xS_{\scriptstyle n}= x + x^2 + x^3 + \dots + x^{n+1}
\end{split}
\end{equation}
$$

Subtracting (2) from (1) then gives
$$
\begin{aligned}
(1-x)S_{\scriptstyle n} &= (1 + x + x^2 + ... + x^n) -  (x + x^2 + x^3 + \dots + x^{n+1})\\
&= 1 - x^{n+1}
\end{aligned}
$$

so

$$
\begin{aligned}
S_{\scriptstyle n} &= \frac{1 - x^{n+1}}{(1-x)}
\end{aligned}
$$