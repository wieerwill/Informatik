---
title: Stochastik
date: Wintersemester 20/21
author: Wieerwill
---

# Stochastik ist 
- Wahrscheinlichkeitstheorie: mathematische "Sprache" zur Modellierung zufälliger Phänomene
  - Ziel: über gegebene Eigenschaften des Systems präzise Aussagen über zukünftige, zufällige Beobachtungen
- und Statistik:
    - Beschreibung beobachteter Daten
    - Schätzen unbekannter Parameter
    - Testen von Hypothesen
    - Vorhersagen unbeobachteter zufälliger Werte
    - Modellwahl und -überprüfung
  - Ziel: basierend auf zufälligen Beobachtungen auf Eigenschaften des Systems“ schließen

## Wahrscheinlichkeiten
### Wahrscheinlichkeitsraum $(\Omega , P)$
- $\Omega$: Grundraum, Menge der Elementarereignisse (oder Ausgänge) (Bsp: $\Omega={heil, kaputt}^x$)
- $\omega \in \Omega$: Elementarereignis, Ausgang (Bsp: $\omega=(heil, heil, heil, kaputt, heil...)$)
- $A \subseteq \Omega$: Ereignis (Bsp: $A={\omega: Anzahl kaputt = 2 }$)
- $P$: Wahrscheinlichkeitsmaß, d.h.
  - Wahrscheinlichkeit, dass A eintritt: $\Omega \supseteq A \rightarrow P(A) \in [0,1]$
  - $\sigma$-Additivität: $P(U_{k\in N} A_k)= \sum_{k\in N} P(A_k)$ für disjunkte $A_k, k\in N$
  - sicheres Ereignis $\Omega$: $P(\Omega)= 1$

## Laplace Expriment
$\Omega$ sei eindlich und $P(\omega)=\frac{1}{*\Omega} \rightarrow$ Laplace-Verteilung oder diskrete Gleichverteilung $\rightarrow$ für $A \subseteq \Omega: P(A)=\sum_{\omega \in A} P(\omega)=\frac{*A}{*\Omega}=\frac{\text{Anzahl "günstige" Ausgänge"}}{\text{Anzahl "alle" Ausgänge}}$ 

Laplace-Verteilung: Alle Ausgänge sind gleichwahrscheinlich $\rightarrow$ Symmetrie

## Urnenmodell
Eine Urne enthält schwarze (S) und weiße (W) Kugeln, insgesamt also $N=S+W$. Man zieht zufällig eine Kugel und nummeriert durch.
- P(i-te Kugel wird gezogen)= $\frac{1}{N}$ für $i=1,..,N$
- P(Kugel ist schwarz)=$\sum_{i=1}^S P(\text{i-te Kugel wird gezogen}) = S \frac{1}{N}=\frac{S}{N}$

### Ziehen ohne zurücklegen
Was, wenn man noch eine Kugel zieht (ohne Zurücklegen)?
$\rightarrow$ Zweistufiges Experiment! Modellieren mit bedingten Wahrscheinlichkeiten.

## Bedingte Wahrscheinlichkeiten
$A,B \subseteq \Omega$ mit $P(B)> 0$; man beobachtet, dass B eintritt

die bedingte Wahrscheinlichkeit von "A gegeben B": $P(A|B)=\frac{P(A \cap B)}{P(B)}$

die totale Wahrscheinlichkeit: $P(A)=\sum_{i=1}^n P(A|B_i)P(B_i)$
