---
title: Automaten, Sprachen und Komplexität
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
f: Menge der mögl Eingaben $\rightarrow$ Menge der mögl Ausgaben

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


> Definition: Grammatiken sind ein Mittel um alle syntaktisch korrekten Sätze (hier Wörter) einer Sprache zu erzeugen.
- in spitzen Klammern: Variable
- ohne spitze Klammern: Terminale

Bsp: 
- [Satz]->[Subjekt][Prädikat][Objekt]
- [Subjekt]->[Artikel][Attribut][Substantiv]
- [Artikel]->e | der | die | das

Eine Folge aus Terminalen nennt man eine Ableitung. Die Ableitung beweist, dass ein Satz zur Sprache gehört, die von der Grammatik erzeugt wird. Mithilfe der Grammatik ist es möglich, unendlich viele Sätze zu erzeugen.

D.h. die zur Grammatik gehörende Sprache ist unendlich.

Grammatiken besitzen Regeln der Form: linke Seite -> rechte Seite

Sowohl auf der linken, als auch auch der rechten Seite können zwei Tpyen von Symbolen vorkommen
- Nicht-Terminale (oder Variablen), aus denen noch weitere Wortbestandteile abgeleitet werden sollen
- Terminale (die "eigentlichen" Symbole)


> Definition: Eine Grammatik G ist ein 4-Tupel $G=(V, \sum, P, S)$ das folgende Bedingungen erfüllt
- V ist eine endliche Menge von Nicht-Terminalen oder Variablen
- $\sum$ ist ein Alphabet (Menge der Terminale) mit $V\cap \sum= \veremtpy$, d.h. kein Zeichen ist gleichzeitig Terminal und Nicht-Terminal
- $P\subseteq (V\cup \sum)^+ \times (v\cup\sum)^*$ ist eine endliche Menge von Regeln oder Produktionen (Produktionsmenge)
- $S\in V$ ist das Startsymbol/ die Startvariable oder das Axiom

Jede Grammatik hat nur endlich viele Regeln!

Konventionen:
- Variablen sind Großbuchstaben (Elemente aus V)
- Terminale sind Kleinbuchstaben (Elemente aus $\sum$)

> Definition: Sei $G=(V, \sum, P, S)$ eine Grammatik und seien $u,v\in (V\cup \sum)^+$. Wir schreiben $u\Rightarrow_G v$ falls eine Produktion $(l,r)\in P$ und Wörter $x,y\in(V\cup\sum)^*$ existieren mit $u=xly$ und $v=xry$.

- Sprechweise: "v wird aus u abgeleitet"
- ist die Grammatik klar, so schreibt man $u\Rightarrow v$
- für $(l,r)\in P$ schreibt man auch $l\rightarrow r$

> Definition: Sei $G=(V, \sum, P, S)$  eine Grammatik. Eine **Ableitung** ist eine endliche Folge von Wörtern
> Ein **Wort** $w\in (V\cup\sum)^*$ heißt Satzform, wenn es eine Ableitung gibt, deren letztes Wort w ist.
> Die **Sprache** $L(G)={w\in \sum^* | S\Rightarrow_G^* w}$ aller Satzformen aus $\sum^*$ heißt von G erzeugte Sprache.

Dabei ist $\Rightarrow_G^*$ der reflexive und transitive Abschluss von $\Rightarrow_G$. D.h. die von G erzeugte Sprache L(G) besteht genau aus den Wörtern, die in beliebig vielen Schritten aus S abgeleitet werden können und nur aus Terminalen besteht.

Bemerkung: Für ein $u\in(V\cip\sum)^*$ kann es entweder gar kein, ein oder mehrere v geben mit $u\Rightarrow_G v$. Ableiten ist also kein deterministischer sondern ein nichtdeterministoscher Prozess. Mit anderen Worten: $\Rightarrow_G$ ist keine Funktion.

Nichtdeterminismus kann verursacht werden durch:
- eine Regel ist an zwei verschiednen Stellen anwendbar
- Zwei verschiedene Regeln sind anwendbar (entweder an der gleichen Stelle oder an verschiedenen Stellen)

- es kann beliebig lange Ableitungen geben, die nie zu einem Wort aus Terminalsymbolen führt
- manchmal können Ableitungen in einer Sackgasse enden, d.h. obwohl noch nichtterminale in einer Satzformen vorkommen, ist keine Regel mehr anwendbar.

## Chomsky Hierarchie
. Typ 0 (Chomsky-0): Jede Grammatik ist vom Typ 0 (Semi-Thue-System)
- Typ 1: Eine Regel heißt kontext-sensitiv, wenn es Wörter $u,v,w\in(V\cup\sum)^*,|v|>0$ und ein Nichtterminal $A\in V$ gibt mit $l=uAw$ und $r=uvw$. Eine Grammatik ist vom Typ 1 (oder kontext-sensitiv) falls
  - alle Regeln aus P kontext-sensitiv sind
  - $(S\rightarrow \epsilon)\in P$ die einzige nicht kontext-sensitive Regel in P ist und S auf keiner rechten Seite einer Regel aus P vorkommt
- Typ 2: eine Regel $(l\rightarrow r)$ heißt kontext-frei wenn $l\in V$ und $r\in (V\cup \sum)^*$ gilt. Eine Grammatik ist vom Typ 2, falls sie nur kontext-freie Regeln enthält
- Typ 3: Eine Regl ist rechtslinear, wenn $l\in V$ und $r\in \sum V\cup {\epsilon}$ gilt. Eine Grammatik ist vom Typ 3 wenn sie nur rechtslineare Regeln enthält

> Definition: Eine Sprache heißt vom Typ i (4i\in {0,1,2,3}$) falls es eine Typ-i-Grammatik gibt mit $L(G)=L$. Wir bezeichnen mit $L$, die Klasse der Sprache vom Typ i. 

Eine Sprache vom Typ i nennt man auch rekursiv aufzählbar (i=0, RE), kontext-sensitiv (i=1, CS), kontext-frei (i=2, CF) oder rechtslinear (i=3, REG).

Bemerkung:
- jede Typ-3/2/1-Grammatik ist vom Typ 0
- jede Typ-3-Grammatik ist vom Typ 2
- Regeln der Form $A\rightarrow \epsilon$ können in Typ 2 und 3 aber nicht in Typ 1 vorkommen

> Satz: Es gibt einen Algorithmus, der als Eingabe eine Typ-1-Grammatik G und ein Wort w bekommst und nach endlicher Zeit entscheidet ob $w\in L(G)$ gilt.

