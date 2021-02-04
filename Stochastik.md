---
title: Stochastik
date: Wintersemester 20/21
author: Wieerwill
---

- [Wahrscheinlichkeiten](#wahrscheinlichkeiten)
  - [Wahrscheinlichkeitsraum $(\Omega , P)$](#wahrscheinlichkeitsraum-omega--p)
  - [Ereignisalgebra](#ereignisalgebra)
  - [Rechengesetze](#rechengesetze)
  - [Vierfeldertafel](#vierfeldertafel)
  - [Absolute Häufigkeit](#absolute-häufigkeit)
  - [Relative Häufigkeit](#relative-häufigkeit)
  - [Mehrstufige Zufallsexperimente](#mehrstufige-zufallsexperimente)
    - [Baumdiagramm](#baumdiagramm)
  - [Kombinatorik](#kombinatorik)
  - [Laplace Expriment](#laplace-expriment)
  - [Stochastische Unabhängigkeit](#stochastische-unabhängigkeit)
  - [Bedingte Wahrscheinlichkeiten](#bedingte-wahrscheinlichkeiten)
    - [Multiplikationssatz](#multiplikationssatz)
    - [Totale Wahrscheinlichkeit](#totale-wahrscheinlichkeit)
    - [Satz von Bayes](#satz-von-bayes)
  - [Zufallsvariable](#zufallsvariable)
    - [Diskrete Zufallsvariable](#diskrete-zufallsvariable)
    - [Stetige Zufallsvariable](#stetige-zufallsvariable)
  - [Wahrscheinlichkeitsverteilung](#wahrscheinlichkeitsverteilung)
    - [Wahrscheinlichkeitsfunktion](#wahrscheinlichkeitsfunktion)
    - [Dichtefunktion](#dichtefunktion)
    - [Verteilungsfunktion](#verteilungsfunktion)
    - [Diskrete Verteilungsfunktionen](#diskrete-verteilungsfunktionen)
    - [Stetige Verteilungsfunktion](#stetige-verteilungsfunktion)
  - [Erwartungswert](#erwartungswert)
  - [Varianz](#varianz)
  - [Standardabweichung](#standardabweichung)
  - [Diskrete & Stetige Verteilung](#diskrete--stetige-verteilung)
- [Deskriptive Statistik](#deskriptive-statistik)
  - [Merkmale](#merkmale)
  - [Lageparamter](#lageparamter)
  - [Streuungsparameter](#streuungsparameter)
  - [Skalenniveaus](#skalenniveaus)

---
# Wahrscheinlichkeiten
> Ein Zufallsexperiment ist ein Versuch mit zufälligem Ausgang.

---
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

---
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

---
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

---
## Vierfeldertafel
Alle vier Felder zusammen entsprechen dem Ergebnisraum $\Omega$

| $\Omega$  | $B$             | $\bar{B}$            |
| --------- | --------------- | -------------------- |
| $A$       | $A\cap B$       | $A\cap \bar{B}$      |
| $\bar{A}$ | $\bar{A}\cap B$ | $\bar{A}\cap\bar{B}$ |


---
## Absolute Häufigkeit
> Die absolute Häufigkeit $H_n(E)$ gibt an, wie oft das Ereignis E innerhalb eines Zufallsexperiments, welches n-mal ausgeführt wird, aufgetreten ist.

Die Summe der absoluten Häufigkeiten ergibt n.

Bsp: Münze wird 20 mal geworfen. Man erhält 8 mal Kopf und 12 mal Zahl:
- $H_{20}(Kopf)=8$
- $H_{20}(Zahl)=12$

---
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

---
## Mehrstufige Zufallsexperimente
### Baumdiagramm
> Ein Baumdiagramm ist eine graphische Darstellung, welche die möglichen Ergebnisse eines bestimmten Ablaufs hierarchischer Entscheidungen zeigt.

Die Summe der Wahrscheinlichkeiten auf den Ästen, die von einem Verzweigungspunkt ausgehen, ist stets 1.

> Die Pfadregeln dienen der Berechnung von Wahrscheinlichkeiten in einem mehrstufigen Zufallsexperiment.

1. (UND) Die Wahrscheinlichkeit eines Elementarereignisses ist gleich dem Produkt der Wahrscheinlichkeiten des zugehörigen Pfades.
     - Bsp: $P(\{SS\})=\frac{1}{2}*\frac{1}{2}$
2. (ODER) Die Wahrscheinlichkeit eines Ereignisses ist gleich der Summe der Wahrscheinlichkeiten aller Pfade, die zu diesem Ereignis führen.
     - Bsp: $P(\{SW, WS\})=\frac{1}{2}*\frac{1}{3} + \frac{1}{3}*\frac{1}{2}$

---
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

|                               |                            | Menge   | Reihenfolge    |
| ----------------------------- | -------------------------- | ------- | -------------- |
| Permutation ohne Wiederholung | $n!$                       | n aus n | beachtet       |
| Permutation mit Wiederholung  | $\frac{n!}{k_1!*k_2!*...}$ | n aus n | beachtet       |
| Variation ohne Wiederholung   | $\frac{n!}{(n-k)!}$        | k aus n | beachtet       |
| Variation mit Wiederholung    | $n^k$                      | k aus n | beachtet       |
| Kombination ohne Wiederholung | $\binom{n}{k}$             | k aus n | nicht beachtet |
| Kombination mit Wiederholung  | $\binom{n+k-1}{k}$         | k aus n | nicht beachtet |



---
## Laplace Expriment
> Ein Zufallsexperiment heißt Laplace-Experiment, wenn alle Elementarereignisse die gleiche Wahrscheinlichkeit besitzen. $P(E)=\frac{|E|}{|\Omega|}$

$\Omega$ sei endlich und $P(\omega)=\frac{1}{\Omega} \rightarrow$ Laplace-Verteilung oder diskrete Gleichverteilung $\rightarrow$ für $A \subseteq \Omega: P(A)=\sum_{\omega \in A} P(\omega)=\frac{*A}{*\Omega}=\frac{\text{Anzahl "günstige" Ausgänge"}}{\text{Anzahl "alle" Ausgänge}}$ 

Vorgehen: Laplace Wahrscheinlichkeit
1. Anzahl aller überhaupt möglichen Elementarereignisse berechnen
2. Anzahl der Elementarereignisse berechnen, bei denen E eintritt
3. Laplace Wahrscheinlichkeit berechnen

> Satz von de Moivre-Laplace: Für eine binomialverteilte Zufallsgröße X mit den Parametern n und p sowie reelle Zahlen a und b gilt $P(a\leq X \leq b)= \int_{a-0,5}^{b+0,5} \varphi_{\mu_i \delta} (x) dx_i$ wobei $\mu = n*p$ und $\delta?\sqrt{n*p*(1-p)}$ ist.

---
## Stochastische Unabhängigkeit
> Zwei Ereignisse A und B sind stochastisch unabhängig, wenn das Eintreten des einen Ereignisses das Eintreten des anderen Ereignisses nicht beeinflusst.

Bsp: 
- Ziehen mit Zurücklegen (unabhängig): Die Wahrscheinlichkeit des Eintretens von A im 2. Zug ist unabhängig davon, ob im 1. Zug das Ereignis B oder $\bar{B}$ eintritt. In beiden Fällen ist die Wahrscheinlichkeit gleich P(A).
- Ziehen ohne Zurücklegen (anhängig): Die Wahrscheinlichkeit des Eintretens von A im 2. Zug ist abhängig davon, ob im 1. Zug das Ereignis B oder $\bar{B}$ eintritt:
$P_B(A)$ ist die Wahrscheinlichkeit von A unter der Bedingung, dass B eingetreten ist. $P_{\bar{B}}(A)$ ist die Wahrscheinlichkeit von A unter der Bedingung, dass $\bar{B}$ eingetreten ist.

Zwei Ereignisse A und B heißen (stochastisch) unabhängig, wenn gilt: $P(A \cap B)=P(A)*P(B)$. Wenn die Ereignisse A und B unabhängig sind, dann sind dies auch $\bar{A}$ und B, A und $\bar{B}$ sowie $\bar{A}$ und $\bar{B}$.

Bei stochastischer Unabhängigkeit zweier Ereignisse hat jeder in die gleiche Richtung zeigende Ast in einem Baumdiagramm die gleiche Wahrscheinlichkeit.

Bei stochastischer Unabhängigkeit zweier Ereignisse ist die Wahrscheinlichkeit eines Feldes in der Vierfeldertafel gleich dem Produkt der Wahrscheinlichkeiten der zugehörigen Zeile und der zugehörigen Spalte.


---
## Bedingte Wahrscheinlichkeiten
$P_B(A)$ ist die Wahrscheinlichkeit von A unter der Bedingung, dass B eingetreten ist; häufig schreibt man auch $P(A|B)$.
die bedingte Wahrscheinlichkeit von "A gegeben B": $P(A|B)=\frac{P(A \cap B)}{P(B)}$

$A,B \subseteq \Omega$ mit $P(B)> 0$; man beobachtet, dass B eintritt nachdem A eingetreten ist.

die totale Wahrscheinlichkeit: $P(A)=\sum_{i=1}^n P(A|B_i)P(B_i)$

---
### Multiplikationssatz
Die Wahrscheinlichkeit eines Elementarereignisses ist gleich dem Produkt der Wahrscheinlichkeiten des zugehörigen Pfades.

Bsp: $P(A\cap B)= P(B)*P_B(A)$

---
### Totale Wahrscheinlichkeit
Die Wahrscheinlichkeit eines Ereignisses ist gleich der Summe der Wahrscheinlichkeiten aller Pfade, die zu diesem Ereignis führen.

Satz der totalen Wahrscheinlichkeit für zwei Ereignisse A und B: 
Bsp: $P(A) = P(A\cap B) + P(A\cap \bar{B}) = P(B)*P_B(A)+P(\bar{B})*P_{\bar{B}}(A)$

---
### Satz von Bayes
Der Satz von Bayes erlaubt das Umkehren von Schlussfolgerungen:
Man geht von einem bekannten Wert $P_A(B)$ aus, mit dessen Hilfe man $P_B(A)$ berechnet.

Um die Formel für die Berechnung von $P_A(B)$ aus $P_B(A)$ zu erhalten, müssen wir zwei Baumdiagramme mit unterschiedlichem Ablauf miteinander verknüpfen. Nach dem Multiplikationssatz gilt: $P(A\cap B)=P(B)*P_B(A)$. Nach $P_B(A)$ aufgelöst gilt $P_B(A)=\frac{P(A\cap B)}{P(B)}$. Nach dem zweiten Multiplikationssatz gilt $P(A\cap B)=P(A)*P_A(B)$. Einsetzten der Formel in die erste Abbildung: $P_B(A)=\frac{P(A\cap B)}{P(B)} \Rightarrow P(A\cap B)=P(A)*P_A(B)$. daraus erhält man den Satz von Bayes $P_B(A)=\frac{P(A)*P_A(B)}{P(B)}$


---
## Zufallsvariable
Eine Funktion X, die jedem Ergebnis $\omega$ des Ergebnisraum $\Omega$ genau eine Zahl x der Menge der reelen Zahlen $\R$ zuordnet, heißt Zufallsvariable. 
Kurz $X:\Omega\rightarrow\R$ 
Veranschaulicht: Eine Zufallsvariable ordnet jedem $\omega_i$ aus $\Omega$ genau ein $x_i$ aus $\R$ zu.

Es gibt drei Möglichkeiten, eine (diskrete) Zufallsvariable darzustellen:
1. als Wertetabelle
2. als abschnittsweise definierte Funktion
3. als Mengendiagramm

---
### Diskrete Zufallsvariable
Eine Zufallsvariable X wird als diskret bezeichnet, wenn sie nur endlich viele oder abzählbar unendlich viele Werte annimmt.

1. Bsp: X:=„Anzahl Würfe, bis zum ersten Mal 6 erscheint“ -> unendliche Wertemenge, die jedoch abzählbar ist
2. Bsp: X:=„Anzahl defekter Artikel in einer Stichprobe“ -> endliche Wertemenge

Diskrete Zufallsvariablen entstehen meist durch einen Zählvorgang.

Diskrete Wahrscheinlichkeitsverteilung: Eine Wahrscheinlichkeitsverteilung gibt an, wie sich die Wahrscheinlichkeiten auf die möglichen Werte einer Zufallsvariablen verteilen.

Erwartungswert :$\mu_x =E(X)=\sum_i x_i*P(X=x_i)$\\
Varianz: $\omega^2_X = Var(X) = \sum_i(x_i-\mu_X)^2 *P(X=x_i)$\\
Standardabweichung: $\omega_X = \sqrt{Var(x)}$

---
### Stetige Zufallsvariable
Eine Zufallsvariable X wird als stetig bezeichnet, wenn sie überabzählbar unendlich viele Werte annimmt.

1. Bsp: X:=„Gewicht einer zufällig ausgewählten Person“ -> unendliche Wertemenge, die nicht abzählbar ist
2. Bsp X:=„Geschwindigkeit eines an einer Radarkontrolle vorbeifahrenden Autos“ -> unendliche Wertemenge, die nicht abzählbar ist

Stetige Zufallsvariablen entstehen meist durch einen Messvorgang.

Erwartungswert: $\mu_X= E(X)=\int_{-\infty}^{\infty} x*f(x)dx$\\
Varianz: $\omega_X^2 =Var(X) = \int_{-\infty}^{\infty} (x-\mu_X)^2 *f(x)dx$\\
Standardabweichung: $\omega_X= \sqrt{Var(X)}$

---
## Wahrscheinlichkeitsverteilung
Eine Wahrscheinlichkeitsverteilung gibt an, wie sich die Wahrscheinlichkeiten auf die möglichen Werte einer Zufallsvariablen verteilen.

Eine Wahrscheinlichkeitsverteilung lässt sich entweder
- durch die Verteilungsfunktion oder
- die Wahrscheinlichkeitsfunktion (bei diskreten Zufallsvariablen)
- bzw. die Dichtefunktion (bei stetigen Zufallsvariablen)
vollständig beschreiben.

---
### Wahrscheinlichkeitsfunktion
Die Wahrscheinlichkeitsfunktion ist ein Hilfsmittel zur Beschreibung einer diskreten Wahrscheinlichkeitsverteilung. 
Eine Funktion f, die jedem x einer Zufallsvariablen X genau ein p aus [0;1] zuordnet, heißt Wahrscheinlichkeitsfunktion. Kurz: $f:x\rightarrow p$

$P(X=x)$ gibt die Wahrscheinlichkeit dafür an, dass die Zufallsgröße X den Wert x annimmt.

Die Wahrscheinlichkeitsfunktion f der Zufallsvariablen X gibt die Wahrscheinlichkeiten für die möglichen Realisationen von X an: $f(x)=P(X=x)= \begin{cases} p_i \text{für } x=x_i (i=1,2,...,n) \\ 0 \text{sonst} \end{cases}$
Für die Summe der Wahrscheinlichkeiten gilt $\sum_{i=1}^n p_i=1$

---
### Dichtefunktion
Die Dichtefunktion ist ein Hilfsmittel zur Beschreibung einer stetigen Wahrscheinlichkeitsverteilung.

Eigenschaften der Dichtefunktion
- Die Dichtefunktion kann nur positive Werte annehmen. $f(x) \geq 0$ für alle $x\in\R$
- Die Fläche unter der Dichtefunktion hat den Inhalt 1. $\int_{-\infty}^{\infty} f(x)dx= 1$

Die Verteilungsfunktion ergibt sich durch Integration der Dichtefunktion: 
$$F(X)=P(X\leq x)=\int_{-\infty}^x f(u)du$$

Die Wahrscheinlichkeit, dass eine stetige Zufallsvariable X einen bestimmten Wert x annimmt, ist stets Null. $P(X=x)=0$

---
### Verteilungsfunktion
Die Verteilungsfunktion ist ein Hilfsmittel zur Beschreibung einer diskreten oder stetigen Wahrscheinlichkeitsverteilung.

Eine Funktion F, die jedem x einer Zufallsvariablen X genau eine Wahrscheinlichkeit $P(X\leq x)$ zuordnet, heißt Verteilungsfunktion: $F:x \rightarrow P(X\leq x$). $P(X\leq x)$ gibt die Wahrscheinlichkeit dafür an, dass die Zufallsvariable X höchstens den Wert x annimmt.
- Die Verteilungsfunktion F einer diskreten Zufallsgröße X ist eine Treppenfunktion
- $F(x)$ ist monoton steigend
- $F(x)$ ist rechtssteitig stetig
- $lim_{x\rightarrow -\infty} F(x)=0$ und $lim_{x\rightarrow +\infty} F(x) =1$

---
### Diskrete Verteilungsfunktionen
1. $P(X\leq a)=F(a)$
2. $P(X<a)= F(a)−P(X=a)$
3. $P(X>a)= 1−F(a)$
4. $P(X\geq a)=1−F(a)+P(X=a)$
5. $P(a<X\leq b)=F(b)−F(a)$
6. $P(a\leq X \leq b)=F(b)−F(a)+P(X=a)$
7. $P(a<X<b) = F(b)−F(a)−P(X=b)$
8. $P(a\leq X < b)=F(b)−F(a)+P(X=a)−P(X=b)$

Eigenschaften einer Verteilungsfunktion
- F(x) ist monoton steigend.
- F(x) ist rechtsseitig stetig.
- $lim_{x\rightarrow -\infty} F(x)=0$ und $lim_{x\rightarrow +\infty} F(x)=1$

---
### Stetige Verteilungsfunktion
$$F(X)=P(X\leq x)=\int_{-\infty}^{x} f(u) du$$

Die Wahrscheinlichkeit, dass eine stetige Zufallsvariable X einen bestimmten Wert x annimmt, ist stets Null. 
- $P(X=x)=0$
- $P(X\leq a)=F(a)$
- $P(a<X\leq b)=F(b)−F(a)$
- $P(X>a)=1−F(a)$

| | Dichtefunktion | Verteilungsfunktion | Erwartungswert | Varianz |
| -- | -- | -- | -- | -- |
| Normalverteilung | $f(x)=\frac{1}{\sigma*\sqrt{2\pi}}*e^{-\frac{1}{2}(\frac{x-\mu}{\sigma})^2}$ | $F(x)=\frac{1}{1-\sigma*\sqrt{2\pi}}\int_{-\infty}^{x}e^{-\frac{1}{2}(\frac{u-\mu}{\sigma})^2}du$ | $E(Y)=\mu$ | $Var(Y)=\sigma^2$
| Stetige Verteilung | $f(x)=\begin{cases}0 \quad\text{ für } x<a \\ \frac{1}{b-a} \quad\text{ für } a\leq x \leq b \\ 0 \quad\text{ für } x>b \end{cases}$ | $F(x)=\begin{cases} 0 \quad\text{ für } x\leq a \\ \frac{x-a}{b-a} \quad\text{ für } a< x < b \\ 1 \quad\text{ für } x\geq b\end{cases}$ | $E(X)=\frac{a+b}{2}$ | $Var(X)=\frac{1}{12}(b-a)^2$ |
| Exponentialverteilung | $f(x)=\begin{cases}0 \quad\text{ f+r } x<0 \\ \frac{1}{\mu}e^{-\frac{x}{\mu}} \quad\text{ für } x\geq 0 \end{cases}$ | $F(x)=\begin{cases} 0 \quad\text{ für } x<0 \\ 1-e^{-\frac{x}{\mu}} \quad\text{ für } x\geq 0 \end{cases}$ | $E(X)=\frac{1}{\lambda}$ | - |
| Binomialverteilung | $f(x)=\binom{n}{x}p^x(1-p)^{n-x}$ | - | $E(X)=np$ | $Var(X)=np(1-p)$ |
| Geometrische Verteilung | $f(x)=(1-p)^{x-1}*p$ | - | $E(X)=\frac{1}{p}$ bzw. $E(Y)=E(X)-1=\frac{1-p}{p}$ | - |
| Hypergeometrische Verteilung | $f(x)=\frac{\binom{X}{x}*\binom{W}{w}}{\binom{N}{n}}$ | - | - | - |
| Poisson-Verteilung | $f(x)=e^{-\lambda}*\frac{\lambda^x}{x!}$ | - | $E(X)=\lambda$ | $Var(X)=\lambda$ |
| empirische Verteilung | $f(x)=\frac{1}{n}$ | $P=\frac{1}{n} \sum_{i=1}^{n} \sigma_{x_i}$ | $E(X)=\frac{1}{n}_{i=1}^n x_i$ | $Var(X)=\frac{1}{n}\sum_{i=1}^n (x_i-\bar{x})^2$ |
| Laplace Verteilung | $f(x)=\frac{1}{2\sigma}e^{-\frac{\| x-\mu \|}{\sigma}}$ | - | - | - |
| Dirac Maß | - | $F(X)=\begin{cases} 1 \quad\text{ falls } x< b \\0 \quad\text{ falls } b \leq x \end{cases}$ | $E(X)=b$ | $Var(X)=0$ |

| diskret | stetig |
| -- | -- |
| Binominalverteilung | Normalverteilung |
| Hypergeometrische Verteilung | Stetige Gleichverteilung |
| Poisson Verteilung | Exponentialverteilung |


---
## Erwartungswert
Der Erwartungswert ist eine Maßzahl zur Charakterisierung einer Wahrscheinlichkeitsverteilung und beschreibt die zentrale Lage einer Verteilung. 

Ist X eine diskrete Zufallsvariable, so heißt $\mu_x = E(X)=\sum_i x_i*P(X=x_i)$ der Erwartungswert von X.

Ist X eine stetige Zufallsvariable, so heißt $\mu_x=E(X)=\int_{-\infty}^{\infty} x*f(x) dx$ der Erwartungswert von X.

---
## Varianz
Die Varianz ist eine Maßzahl zur Charakterisierung einer Wahrscheinlichkeitsverteilung und beschreibt die erwartete quadratische Abweichung der Zufallsvariablen von ihrem Erwartungswert.

Ist X eine diskrete Zufallsvariable, so heißt $\delta_x^2 = Var(X) = \sum_i (x_i-\mu_x)^2*P(X=x_i)$ die Varianz von X. 

Ist X eine stetige Zufallsvariable, so heißt $\delta_x^2 = Var(X)= \int_{-\infty}^{\infty} (x-\mu x)^2*f(x) dx$ die Varianz von X.

Verschiebungssatz: $Var(X)=E(X^2)-(E(X))^2$

---
## Standardabweichung
Die Standardabweichung ist eine Maßzahl zur Charakterisierung einer Wahrscheinlichkeitsverteilung und beschreibt die erwartete Abweichung der Zufallsvariablen von ihrem Erwartungswert.
$$\delta_x = \sqrt{Var(X)}$$

---
## Diskrete & Stetige Verteilung
Eine Wahrscheinlichkeitsverteilung gibt an, wie sich die Wahrscheinlichkeiten auf die möglichen Werte einer Zufallsvariablen verteilen. 
Eine Verteilung lässt sich entweder durch eine
- Wahrscheinlichkeitsfunktion (diskret)
- Dichtefunktion (stetig) oder
- Verteilungsfunktion (beide)

vollständig beschreiben.


---
# Deskriptive Statistik
Aufgabe der deskriptiven Statistik ist es, große Datenmengen auf einige wenige Maßzahlen zu reduzieren, um damit komplexe Sachverhalte übersichtlich darzustellen.

Die Menge aller Elemente, auf die ein Untersuchungsziel in der Statistik gerichtet ist, heißt Grundgesamtheit. Eine Datenerhebung der Grundgesamtheit nennt man Vollerhebung, wohingegen man eine Datenerhebung einer Stichprobe als Stichprobenerhebung bezeichnet. Die in einer Stichprobe beobachteten Werte heißen Stichprobenwerte oder Beobachtungswerte.

---
## Merkmale
Merkmale sind jene Eigenschaften, die bei einer Datenerhebung untersucht werden.

| qualititativ || vs.| quantitativ ||
| -- | -- | -- | -- | -- |
| nominal (Ausprägung) | ordinal (Rangfolge) |\|| diskret (ganzzahlig) | stetig (beliebig) |
| Geschlecht | Schulnote |\|| Schülerzahl | Gewicht |

- Qualitative Merkmale lassen sich artmäßig erfassen.
  - nominale Merkmale (Bsp. Geschlecht): Einzelne Ausprägungen des Merkmals lassen sich feststellen und willkürlich nebeneinander aufreihen. Es lässt sich keine Aussage über eine Reihenfolge oder über Abstände einzelner Ausprägungen machen.
  - ordinale Merkmale (Bsp. Schulnoten): Einzelne Merkmale lassen sich zwar nicht im üblichen Sinne messen, wohl aber in eine Reihenfolge bringen. Eine Aussage über den Abstand der Ränge lässt sich dagegen nicht machen.
- Quantitative (metrische) Merkmale lassen sich zahlenmäßig erfassen.
  - diskrete Merkmale (Bsp. Schülerzahl): Es gibt nur bestimmte Ausprägungen, die sich abzählen lassen. Die Merkmalsausprägungen diskreter Merkmale sind also ganze, meist nichtnegative Zahlen.
  - stetige Merkmale (Bsp. Gewicht): Einzelne Ausprägungen eines Merkmals können jeden beliebigen Wert innerhalb eines gewissen Intervalls annehmen.

---
## Lageparamter
Unter dem Begriff Lageparameter werden alle statistischen Maßzahlen zusammengefasst, die eine Aussage über die Lage einer Verteilung machen.
| Lageparamter | | 
| -- | -- |
| Arithmetisches Mittel | $x=\frac{x_1+x_2+\dots+x_n}{n}=\frac{1}{n}*\sum_{i=1}^n x_i$ |
| Geometrisches Mittel | $\bar{x}_{geom} = \sqrt[n]{x_1*x_2*\dots*x_n}$ |
| Harmonisches Mittel | $\bar{x}_{harm} = \frac{n}{\frac{1}{x_1}+\dots+\frac{1}{x_n}}$ |
| Median | $\tilde{x} = \begin{cases} x_{\frac{n+1}{2}} \quad\text{ für n ungerade} \\ \frac{1}{2}(x_{\frac{n}{2}}+x_{\frac{n}{2}+1}) \quad\text{ für n gerade}\end{cases}$ Der Wert, welcher größer oder gleich 50% aller Werte ist. |
| Modus | $\bar{x}_d=$ Häufigster Beobachtungswert |

---
## Streuungsparameter
Unter dem Begriff Streuungsparameter werden alle statistischen Maßzahlen zusammengefasst, die eine Aussage über die Verteilung von einzelnen Werten um den Mittelwert machen.

| Streuungsparameter | |
| -- | -- |
| Spannweite | $R=x_{max}-x_{min}$ |
| Interquartilsabstand | $IQR=Q_{0,75}-Q_{0,25}$ |
| Mittlere absolute Abweichung | $D=\frac{1}{n} * \sum_{i=1}^{n} \|x_i-\bar{x}\|$ |

- Das 0,75-Quartil $Q_{0,75}$ entspricht dem Wert, welcher größer oder gleich 75% aller Werte ist.
- Das 0,25-Quartil $Q_{0,25}$ entspricht dem Wert, welcher größer oder gleich 25% aller Werte ist.


---
## Skalenniveaus

| Skalen | diskret | qualitiativ | | für | 
| -- | -- | -- | -- | -- |
| Nominalskala    |   |   | Klassifikation, Kategorien | Geschlecht, Studiengang |
| Ordinalskala    |   |   | Rangordnung ist definiert | Schulnoten |
| Intervallskala  |   |   | Rangordnung und Abstände sind definiert | Temperatur |
| Verhältnisskala |   |   | Rangordnung, Abstände und natürlicher Nullpunkt definiert | Gehalt, Gewicht |
| Absolutskala    | Y | Y | Rangordnung, Abstände, natürlicher Nullpunkt und natürliche Einheiten | Anzahl Fachsemester |
