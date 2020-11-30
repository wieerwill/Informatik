---
title: Stochastik
date: Wintersemester 20/21
author: Wieerwill
---

# Wahrscheinlichkeiten
> Ein Zufallsexperiment ist ein Versuch mit zufälligem Ausgang.
## Wahrscheinlichkeitsraum $(\Omega , P)$
- Ergebnis-/Grundraum $\Omega$, Menge aller möglichen Elementarereignisse (Bsp: $\Omega={heil, kaputt}^x$)
  - die Anzahl aller möglichen Ergebnisse heißt Mächtigkeit des Ergebnisraums $|\Omega|$ (Bsp: $|\Omega|=2$)
  - Endlicher Ergebnisraum: die Elemente können abgezählt und eine Obergrenze angegeben werden
  - Abzählbar-unendlicher Ergebnisraum: die Elemente können abgezählt aber keine Obergrenze angegeben werden
  - Überabzählbar-unendlicher Ergebnisraum: die Elemente können nicht abgezählt werden
- Ergebnis/Ausgang $\omega \in \Omega$ (Bsp: $\omega=(heil, heil, heil, kaputt, heil...), \omega_1=(heil)$)
  - ein Ergebnis, das genau ein Element enthält, heißt ELementarergebnis
- Ereignis $A \subseteq \Omega$ (Bsp: $A={\omega: Anzahl kaputt = 2 }$)
  - das Ereignis, das kein Element enthält, heißt unmögliches Ereignis (Bsp "Augenzahl größer 6" beim Würfelwurf)
  - das Ereignis, das genau ein Element enthält, heißt Elementarereignis
  - Ein Ereignis, das mehr als ein Element enthält, heißt zusammengesetztes Ereignis.
  - das Ereignis, das alle Elemente von $\Omega$ enthält, heißt sicheres Ereignis $\Omega$: $P(\Omega)= 1$
- Wahrscheinlichkeitsmaß/Ereignisraum, die Menge aller Ereignisse, $P(\Omega)$
  - setzt sich zusammen aus dem unmöglichen Ereignis, den Elementarereignissen, den mehrelementigen Teilmengen und dem sicheren Ereignis (Bsp $P(\Omega)=\{\{\},\{heil\},\{kaputt\},\{heil, kaputt\} \}$)
  - die Anzahl der möglichen Ereignisse heißt Mächigkeit des Ereignisraums $|P(\Omega)|$
  - Der Ereignisraum besteht aus $2^{|\Omega|}$ Ereignissen
- Wahrscheinlichkeit, dass A eintritt: $\Omega \supseteq A \rightarrow P(A) \in [0,1]$
- $\sigma$-Additivität: $P(U_{k\in N} A_k)= \sum_{k\in N} P(A_k)$ für disjunkte $A_k, k\in N$

## Ereignisalgebra
- Vereinigung: $A\cup B= \{\omega | \omega\in A \vee \omega\in B \}$
  - Bsp: $A=\{1,2\}, B=\{2,3\}, A\cup B=\{1,2,3\}$
- Durchschnitt: $A\cap B = \{\omega | \omega\in A \wedge \omega\in B \}$
  - Bsp: $A=\{1,2\}, B=\{2,3\}, A\wedge B=\{2\}$
- Gegenereignis: $\bar{A} = \{\omega | \omega\not\in A\}$
  - Bsp: $A=\{1,2\}, \Omega=\{1,2,3,4,5,6\}, \bar{A}=\{3,4,5,6\}$
- Differenz $A \backslash B = A\cap\bar{B} = \{\omega| \omega\in A \wedge \omega\not\in B\}$
  - Bsp: $A=\{1,2\}, B=\{2,3\}, A\backslash B=\{1\}$
- Symmetrische Differenz $(A\cap \bar{B})\cup(\bar{A}\cap B)$
  - die Menge aller Elemente, die zu A oder zu B, nicht aber zu beiden Ereignissen gehören
  - Bsp: $A=\{1,2\}, B=\{2,3\}, A\cup B=\{1,3\}$
- disjunkte Ereignisse $A\cap B = \varnothing$
  - wenn sie keine gemeinsamen Elemente haben (unvereinbar)

## Rechengesetze
- Kommutativ: 
  - $A\cup B = B\cup A$
  - $A\cap B = B\cap A$
- Assoziativ: 
  - $(A\cup B)\cup C = A\cup(B\cup C)$
  - $(A\cap B)\cap C = A\cap(B\cap C)$
- Distributiv: 
  - $A\cap(B\cup C)=(A\cap B)\cup(A\cap C)$
  - $A\cup(B\cap C)= (A\cup B)\cap (A\cup C)$
- Absorption
  - $A\cap(A\cup B)=A$
  - $A\cup(A\cap B)=A$
- Idempotenz
  - $A\cap A=A$
  - $A\cup A=A$
- De-Morgan-Gesetz
  - $\bar{A}\cap\bar{B}=\overline{A\cup B}$
  - $\bar{A}\cup\bar{B}=\overline{A\cap B}$
- Neutrale Elemente
  - $A\cap \Omega=A$
  - $A\cup \varnothing = A$
- Dominante Elemente
  - $A\cap \varnothing = \varnothing$
  - $A\cup \Omega = \Omega$
- Komplemente
  - $A\cap \bar{A} = \varnothing$
  - $A\cup \bar{A} = \Omega$
  - $\bar{\bar{A}} = A$

## Vierfeldertafel
Alle vier Felder zusammen entsprechen dem Ergebnisraum $\Omega$

| $\Omega$  | $B$             | $\bar{B}$           |
| --        | --              | --                  |
| $A$       | $A\cap B$       | $A\cap \bar{B}$     |
| $\bar{A}$ | $\bar{A}\cap B$ | $\bar{A}\cap\bar{B}$|


## Absolute Häufigkeit
> Die absolute Häufigkeit $H_n(E)$ gibt an, wie oft das Ereignis E innerhalb eines Zufallsexperiments, welches n-mal ausgeführt wird, aufgetreten ist.

Die Summe der absoluten Häufigkeiten ergibt n.

Bsp: Münze wird 20 mal geworfen. Man erhält 8 mal Kopf und 12 mal Zahl:
- $H_{20}(Kopf)=8$
- $H_{20}(Zahl)=12$

## Relative Häufigkeit
> Tritt ein Ereignis $E$ bei $n$ Versuchen $k$-mal ein, so heißt die Zahl $h_n(E)=\frac{k}{n}$ relative Häufigkeit des Ereignisses E.

anders: $h_n(E)=\frac{H_n(E)}{n}$

Bsp: Münze wird 20 mal geworfen. Man erhält 8 mal Kopf und 12 mal Zahl:
- $h_{20}(Kopf)=\frac{8}{20}=0,4$
- $h_{20}(Zahl)=\frac{12}{20}=0,6$

- die Relative Häufigkeit nimmt Werte zwischen 0 und 1 an
- die relative Häufigkeit des sicheren Ereignisses ist 1 $h_n(\Omega)=1$
- die relative Häufigkeit des unmöglichen Ereignisses ist 0 $h_n(\{\})=0$
- jedes Ereignis und sein Gegenereignis ergänzen sich zum Ergebnisraum $\Omega$, d.h. $hn(\bar{E})=1-h_n(E)$
- $h_n(A\cup B)= h_n(A)+h_n(B)-h_n(A\cap B)$
- $H_n(E)=h_n(E)*n$

## Mehrstufige Zufallsexperimente
### Baumdiagramm
> Ein Baumdiagramm ist eine graphische Darstellung, welche die möglichen Ergebnisse eines bestimmten Ablaufs hierarchischer Entscheidungen zeigt.

Die Summe der Wahrscheinlichkeiten auf den Ästen, die von einem Verzweigungspunkt ausgehen, ist stets 1.

> Die Pfadregeln dienen der Berechnung von Wahrscheinlichkeiten in einem mehrstufigen Zufallsexperiment.

1. (UND) Die Wahrscheinlichkeit eines Elementarereignisses ist gleich dem Produkt der Wahrscheinlichkeiten des zugehörigen Pfades.
     - Bsp: $P(\{SS\})=\frac{1}{2}*\frac{1}{2}$
2. (ODER) Die Wahrscheinlichkeit eines Ereignisses ist gleich der Summe der Wahrscheinlichkeiten aller Pfade, die zu diesem Ereignis führen.
     - Bsp: $P(\{SW, WS\})=\frac{1}{2}*\frac{1}{3} + \frac{1}{3}*\frac{1}{2}$

## Kombinatorik
> Die Kombinatorik hilft bei der Bestimmung der Anzahl möglicher Anordnungen (Permutationen) oder Auswahlen (Variationen oder Kombinationen) von Objekten.

- Permutation
  - $k=n$ (d.h. es werden alle Elemente k der Grundmenge n betrachtet)
  - Reihenfolge der Elemente wird berücksichtigt
- Variation
  - $k<n$ (d.h. es wird nur eine Stichprobe - also k Elemente der Grundmenge n betrachtet)
  - Reihenfolge der Elemente wird berücksichtigt $\rightarrow$ Variation = geordnete Stichprobe
- Kombination
  - $k<n$ (d.h. es wird nur eine Stichprobe - also k Elemente der Grundmenge n betrachtet)
  - Reihenfolge der Elemente wird nicht berücksichtigt $\rightarrow$ Kombination = ungeordnete Stichprobe

1. Permutation ohne Wiederholung
    - Für das erste Objekt gibt es $n$ Platzierungsmöglichkeiten. Für das zweite Objekt verbleiben $(n−1)$ Möglichkeiten, für das dritte Objekt $(n−2)$ ... und für das letzte Objekt verbleibt nur noch eine Möglichkeit.
    - kurz: $n!$
2. Permutation mit Wiederholung
    - Sind genau k Objekte identisch, dann sind diese auf ihren Plätzen vertauschbar, ohne dass sich dabei eine neue Reihenfolge ergibt. Auf diese Weise sind genau k! Anordnungen gleich.
    - kurz: $\frac{n!}{k!}$ und mit mehreren Gruppen $\frac{n!}{k_1! * k_2!...}$
3. Variation ohne Wiederholung
    - Für das erste Objekt gibt es n Platzierungsmöglichkeiten. Für das zweite Objekt verbleiben $(n-1)$ Möglichkeiten, für das dritte Objekt $(n-2)$ ...und für das letzte Objekt verbleiben noch $(n-k+1)$ Möglichkeiten.
    - kurz: $\frac{n!}{(n-k)!}$
4. Variation mit Wiederholung
    - Für das erste Objekt gibt es n Auswahlmöglichkeiten. Da Objekte mehrfach ausgewählt werden dürfen, gibt es auch für das zweite, dritte und k-te Objekt n Möglichkeiten.
    - $n^k$
5. Kombination ohne Wiederholung
    - Der einzige Unterschied zwischen einer Variation ohne Wiederholung und einer Kombination ohne Wiederholung ist die Tatsache, dass bei der Kombination im - Gegensatz zur Variation - die Reihenfolge der Objekte keine Rolle spielt.
    - kurz: $\frac{n!}{(n-k)!*k!} = \binom{n}{k}$
6. Kombination mit Wiederholung
    - Durch eine kleine Modifikation des Zählers und des Nenners gelangen wir schließlich zur Formel für eine Kombination mit Wiederholung
    - $\frac{(n+k-1)!}{(n-1)!*k!} = \binom{n+k-1}{k}$

| | | Menge | Reihenfolge |
| -- | -- | -- | -- |
| Permutation ohne Wiederholung | $n!$ | n aus n | beachtet |
| Permutation mit Wiederholung | $\frac{n!}{k_1!*k_2!*...}$ | n aus n | beachtet |
| Variation ohne Wiederholung | $\frac{n!}{(n-k)!}$ | k aus n | beachtet |
| Variation mit Wiederholung | $n^k$ | k aus n | beachtet |
| Kombination ohne Wiederholung | $\binom{n}{k}$ | k aus n | nicht beachtet |
| Kombination mit Wiederholung | $\binom{n+k-1}{k}$ | k aus n | nicht beachtet |



## Laplace Expriment
> Ein Zufallsexperiment heißt Laplace-Experiment, wenn alle Elementarereignisse die gleiche Wahrscheinlichkeit besitzen. $P(E)=\frac{|E|}{|\Omega|}$

$\Omega$ sei eindlich und $P(\omega)=\frac{1}{\Omega} \rightarrow$ Laplace-Verteilung oder diskrete Gleichverteilung $\rightarrow$ für $A \subseteq \Omega: P(A)=\sum_{\omega \in A} P(\omega)=\frac{*A}{*\Omega}=\frac{\text{Anzahl "günstige" Ausgänge"}}{\text{Anzahl "alle" Ausgänge}}$ 

## Bedingte Wahrscheinlichkeiten
$A,B \subseteq \Omega$ mit $P(B)> 0$; man beobachtet, dass B eintritt

die bedingte Wahrscheinlichkeit von "A gegeben B": $P(A|B)=\frac{P(A \cap B)}{P(B)}$

die totale Wahrscheinlichkeit: $P(A)=\sum_{i=1}^n P(A|B_i)P(B_i)$
