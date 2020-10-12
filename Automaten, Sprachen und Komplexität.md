---
title: automaten, Sprachen und Komplexität
date: Wintersemester 20/21
author: Robert Jeutter
---

Literaturempfehlung: Theoretische Informatik - kurz gefasst, Uwe Schöning, Spektrum Akademischer Weg

# Einführung
## Grundfrage
Welche Probleme können mit unseren begrenzten Resourcen gelöst werden und welche nicht?

bzw

Wo ist die grenze der Problemlösung mit unseren Resourcen?

## Probleme (als Abbildung)
f: menge der mögl Eingaben $\rightarrow$ Menge der mögl Ausgaben

Spezialfall A={0,1} heißt Entscheidungsproblem. Sie ist gegeben durch die Menge der Eingaben. 

Mengen nennt man "Sprachen"

## (beschränkte) Resourcen
- Art des Speicherzugriffs
- Art der Steuereinheit (deterministisch?)
- Dauer der Berechnung
- Größe des Speichers 

# Grundbegriffe
Natürliche Zahlen $\N = {0,1,2,3,...}$

> Definition: Für eine Menge X ist X* die Menge der endlichen Folgen über X.

> Definition: Ein Alphabet ist eine endliche nichtleere Menge.

üblicherweise heißen Alphabete hier: $\Sum, \Gamma, \Delta$
Ist $\Sum$ Alphabet, so nennen wir die Elemente oftBuchstaben.
Ist $\Sum$ ein Alphabet, so heißen die Elemente von $\Sum*$ auch Wörter über $\Sum$ (auch String/Zeichenkette)

Beispiele:
- Alphabete:{0},{0,1,2},...{A,K,S,0,1,2,3,4,5,6,7,8,9}, {groß,klein}
- keine Alphabete: $\varempty, \N, \Q$
- Das Alphabet{0,1,2}hat also die drei Buchstaben 0, 1 und 2.
- Das Alphabet{groß,klein}hat die zwei Buchstabengroßundklein
- (0),()und(1,2,0,0) sind also Wörter über dem Alphabet{0,1,2}.
- (groß),(klein,groß),(klein,groß,klein)und()sind Wörter überdem Alphabet{groß,klein}.
- (1,2,0,0) wird geschrieben als  1 2 0 0
- (1) wird geschrieben als1
- () wird geschrieben als $\epsilon$ (dasleere Wort)
- (klein,groß,klein) wird geschrieben als klein.groß.klein

> Definition: Sind $u=(a_1, a_2, ...a_n)$ und $v=(b_1, b_2,...,b_n)$ Wörter, so ist $u*v$ das Wort $(a_1,a_2,...a_n,b_1,b_2,...,b_n)$; es wird als Verkettung/Konkatenation von u und v bezeichnet.

An Stelle von $u*v$ schreibt man auch $uv$

Beobachtung: $\Sum* x \Sum* \rightarrow \Sum*$ ist eine Abbildung
- Assoziativ: $u*(w*v)=(u*w)*v$
- neutrales Element: $\epsilon * u = u * \epsilon = u$

Kürzer: $(\Sum, *, \epsilon)$ ist ein Monoid

> Definition: Für $\omega \in \Sum*$ und $n\in \N$ ist $w^n$ induktiv definiert

$w^n=\epsilon \text{ falls } n=0; \omega*\omega^{n-1} \text{ falls } n>0$

> Definition: Seien y,w Wörter über $\Sum$. Dann heißt
- Präfix/Anfangsstück von w, wenn es $z\in\Sum*$ gibt mit $yz=w$
- Infix/Faktor von w, wenn es $x,z \in \Sum*$ gibt mit $xyz=w$
- Suffix/Endstück von w, wenn es $x\in \Sum*$ gibt mit $xy=w$

> Definition: Sei $\Sum$ ein Alphabet. Teilmengen von $\Sum*$ werden formale Sprachen über $\Sum$ genannt.

> Definition: Eine Menge L ist eine formale Sprache wenn es ein Alphabet $\Sum$ gibt, so dass L formale Sprache über $\Sum$ ist (d.h. $L\subseteq \Sum*$)

> Definition: Sind $L_1$ und $L_2$ Sprachen, so heißt die Sprache $L_1 L_2={w | \exists w_1 \in L_1, w_2 \in L_2: w=w_1 w_2}$ die Konkatenation/Verkettung von $L_1$ und $L_2$.

Beispiele:
- ${0}*{1}*={0^i1^j | i,j>0}
- ${0}\cup {1}{0,1}*$ ist die Menge der Binärzahlen
  
- Die Verkettung von Sprachen ist assoziativ
- es gibt ein neutrales Element $\epsilon$
- es gibt ein auslöschendes Element $\varempty$

> Definition: Sei L Sprache und $n\in\N$. Dann ist $L^n$ induktiv definiert:
$L^n = {\epsilon} \text{ falls } n=0; LL^{n-1} \text{ falls } n>0$

> Definition: Sei L eine Sprache. Dann ist $L*=\bigcup_{n\geq 0} L^n$ der Kleene-Abschluss oder die Kleene-Iteration von L. Weiter ist $L+ = \bigcup_{n\geq 0} L^n$

$L+ = L* L* = L* * L$

Beobachtung: Sei $\Sum$ Alphabet.
- Sind $L_1$ und $L_2$ Sprachen über $\Sum$, so auch die Verkettung $L_1L_2$, die Kleene-Iteration $L_1*$, die positive Iteration $L_1+$, die Vereinigung $L_1\cup L_2$, die Differenz $L_1 \ L_2$ und der Schnitt $L_1 \cap L_2$.
- $\varempty, \Sum, \Sum*$ sind Sprachen über $\Sum$

Prioritätsregeln für Operationen auf Sprachen
- Potenz/Iteration binden stärker als Konkatenation
- Konkatenation stärker als Vereinigung/Durchschnitt/Differenz
Sprechweise: "Klasse" von Sprachen ( nicht "Menge")

