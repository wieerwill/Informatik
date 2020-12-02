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

üblicherweise heißen Alphabete hier: $\sum, \Gamma, \Delta$
Ist $\sum$ Alphabet, so nennen wir die Elemente oft Buchstaben.
Ist $\sum$ ein Alphabet, so heißen die Elemente von $\sum*$ auch Wörter über $\sum$ (auch String/Zeichenkette)

Beispiele:
- Alphabete:{0},{0,1,2},...{A,K,S,0,1,2,3,4,5,6,7,8,9}, {groß,klein}
- keine Alphabete: $\emptyset, \N, Q$
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

Beobachtung: $\sum* x \sum* \rightarrow \sum*$ ist eine Abbildung
- Assoziativ: $u*(w*v)=(u*w)*v$
- neutrales Element: $\epsilon * u = u * \epsilon = u$

Kürzer: $(\sum, *, \epsilon)$ ist ein Monoid

> Definition: Für $\omega \in \sum*$ und $n\in \N$ ist $w^n$ induktiv definiert

$w^n=\epsilon \text{ falls } n=0; \omega*\omega^{n-1} \text{ falls } n>0$

> Definition: Seien y,w Wörter über $\sum$. Dann heißt
- Präfix/Anfangsstück von w, wenn es $z\in\sum*$ gibt mit $yz=w$
- Infix/Faktor von w, wenn es $x,z \in \sum*$ gibt mit $xyz=w$
- Suffix/Endstück von w, wenn es $x\in \sum*$ gibt mit $xy=w$

> Definition: Sei $\sum$ ein Alphabet. Teilmengen von $\sum*$ werden formale Sprachen über $\sum$ genannt.

> Definition: Eine Menge L ist eine formale Sprache wenn es ein Alphabet $\sum$ gibt, so dass L formale Sprache über $\sum$ ist (d.h. $L\subseteq \sum*$)

> Definition: Sind $L_1$ und $L_2$ Sprachen, so heißt die Sprache $L_1 L_2={w | \exists w_1 \in L_1, w_2 \in L_2: w=w_1 w_2}$ die Konkatenation/Verkettung von $L_1$ und $L_2$.

Beispiele:
- ${0}*{1}*={0^i1^j | i,j>0}
- ${0}\cup {1}{0,1}*$ ist die Menge der Binärzahlen
  
- Die Verkettung von Sprachen ist assoziativ
- es gibt ein neutrales Element $\epsilon$
- es gibt ein auslöschendes Element $\emptyset$

> Definition: Sei L Sprache und $n\in\N$. Dann ist $L^n$ induktiv definiert:
$L^n = {\epsilon} \text{ falls } n=0; LL^{n-1} \text{ falls } n>0$

> Definition: Sei L eine Sprache. Dann ist $L*=\bigcup_{n\geq 0} L^n$ der Kleene-Abschluss oder die Kleene-Iteration von L. Weiter ist $L+ = \bigcup_{n\geq 0} L^n$

$L+ = L* L* = L* * L$

Beobachtung: Sei $\sum$ Alphabet.
- Sind $L_1$ und $L_2$ Sprachen über $\sum$, so auch die Verkettung $L_1L_2$, die Kleene-Iteration $L_1*$, die positive Iteration $L_1+$, die Vereinigung $L_1\cup L_2$, die Differenz $L_1 \ L_2$ und der Schnitt $L_1 \cap L_2$.
- $\emptyset, \sum, \sum*$ sind Sprachen über $\sum$

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
- $\sum$ ist ein Alphabet (Menge der Terminale) mit $V\cap \sum= \varnothing$, d.h. kein Zeichen ist gleichzeitig Terminal und Nicht-Terminal
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

Bemerkung: Für ein $u\in(V\cup\sum)^*$ kann es entweder gar kein, ein oder mehrere v geben mit $u\Rightarrow_G v$. Ableiten ist also kein deterministischer sondern ein nichtdeterministoscher Prozess. Mit anderen Worten: $\Rightarrow_G$ ist keine Funktion.

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


# Rechtslineare Sprachen
werden durch Typ 3 erzeugt

## endliche Automaten (Maschinen)
anderer blickwinkel für rechtslineare Sprachen (ohne Speichereinheit)
Eingabe: Folge von " Buchstaben"

> Definition: ein deterministischer endlicher Automat M ist ein 5-Tupel $M=(Z, \sum, z_0, \delta, E)$
- $Z$ eine endliche Menge von Zuständen
- $\sum$ das Eingabealphabet (mit $Z\cap\sum = \emptyset$)
- $z_0\in Z$ der Start/Anfangszustand
- $\delta: Z \times \sum \rightarrow Z$ die Überführungs/Übergangsfunktion
- $E\subseteq Z$ die Menge der Endzustände

Abkürzung: DFA (deterministic finite automaton)

Bsp:
- $Z={0,1}$
- $\sum = \{a,b\}$
- $z_0=0$
- $\delta(0,a)=\delta(1,b)=1, \delta(1,a)=\delta(0,b)=0$
- $E={0}$
- 
in DFA darf es nur einen einzigen Startzustand geben!
im Graphendiagramm: jeder Knoten hat die anzahl der alphabete als kanten

die (einmal lesende) $\delta$ Funktion wird verallgemeinert: $\hat{\delta}$, die die Übergänge für ganze Wörter ermittelt

> Definition: Zu einem gegebenen DFA definieren wir die Funktion $\hat{\delta}: Z \times \sum^* \rightarrow Z$ induktiv wie folgt, wobei $z\in Z$, $w\in\sum^+$ und $a\in \sum$:
- $\hat{\delta}(z, \epsilon) = z$
- $\hat{\delta}(z,aw)= \hat{\delta}(\delta(z,a),w)$

Der Zustand $\hat{\delta}(z,w)$ ergibt sich indem man vom Zustand z aus dem Pfad folgt der mit w beschriftet ist.

> Definition: die von einem DFA **akzeptierte Sprache** ist: $L(M)={w\in\sum^* | \hat{\delta}(z_0,w)\in E}$

d.h. wenn der Pfad der im Anfangszuststand beginnt nach den Übergangen durch w-markierte Pfade in einem Endzustand endet

> Definition: Eine Sprache $L \supseteq \sum^*$ ist regulär, wenn es einen DFA mit $L(M)=L$ gibt. 
(wird von einem DFA akzeptiert)


> Proposition: Jede reguläre Sprache ist rechtslinear
Beweis: sei M ein DFA, definiere eine Typ-3 Grammatik G wie folgt:
- $V=Z$
- $S=z_0$
- $P={z\rightarrow a \delta(z,a) | z\in Z, a\in \sum} \cup {z\rightarrow \epsilon | z\in E}$ (Regeln abgeleitet aus Graphen mit Kanten; letzte Regel um ENdzustand in ein Terminal zu wandeln).

Behauptung: für alle $z,z'\in Z$ und $w\in \sum^*$ gilt: $z\Rightarrow^*_G wz' \Leftrightarrow \hat{\delta} (z,w)=z'$. Beweis durch Induktion über $|w|$.
Für $w\in\sum^*$ gilt dann $w\in L(G) \Leftrightarrow \exist z\in V: z_0\Rightarrow^*_G wz \Rightarrow_G w \Leftrightarrow \exists z\in Z:\hat{\delta}(z_o, w)=z$ und $Zz\rightarrow \epsilon)\in P \leftrightarrow \hat{\delta}(z_0, w)\in E \leftrightarrow w\in L(M)$

ALso ist $L(M)=L(G)$ und damit rechtslinear

DFAs sind deterministisch, Grammatiken nichtdeterministisch

erweiterte DFA um Nichtdeterminismus zu NFAs (nichtdeterministic finite automaton)

> Definition: ein nichtdeterministischer endlicher Automat M ist ein 5-Tupel $M=(Z,\sum,S,\delta,E)$ mit
- $Z$ ist eine endliche Menge von Zuständen
- $\sum$ ist das Eingabealphabet
- $S\subseteq Z$ die Menge der Startzustände (können mehrere sein)
- $\delta: Z \times \sum \rightarrow P(Z)$ ist die (Menge der) Überführungs/Übergangsfunktion
- $E\subseteq Z$ die Menge der Endzustände

$P(Z)={Y | Y \subseteq Z}$ ist die Potenzmenge von Z (die Menge aller Teilmengen von Z). Diese Menge wird manchmal auch mit "2^Z$ bezeichnet

Bsp
- $\delta={2,3}$ heißt aus einem Zustand gibt es zwei mögliche Wege mit gleicher belegung
- $\delta=\emptyset$ heißt es gibt keinen Weg aus dem Zustand

> Definition: Zu einem gegebenen NFA M definieren wir die Funktion $\hat{\delta}:P(Z)\times \sum^* \rightarrow P(Z)$ induktiv wie folgt, woebei $Y \subseteq Z$, $w\in \sum^*$ und $a\in\sum$: $\hat{\delta}(Y,\epsilon)=Y$, $\hat{\delta}(Y,aw)=\hat{delta}(\bigcup \delta(z,a),w)$

> Definition: die von einem NFA M akzeptierte Sprache ist $L(M)={w\in \sum^* | \hat{\delta}(S,w)\cap E \not = \emptyset}$
( Das Wort wird akzeptiert wenn es mindestens einen Pfad vom anfangs in den endzustand gibt)

> Proposition: Jede von einem NFA akzeptierte Sprache ist regulär
Zustände des DFA sind Mengen von Zuständen des NFA, daher auch Potzenmengenkonstruktion

$w\in L(M') \leftrightarrow \hat\gamma (S,w)\in F \leftrightarrow \hat\delta(S,w)\cap E\not = \emptyset \leftrightarrow w\in L(M)$ und damit $l(M')=L(M)$

> Proposition: Zu jeder rechtslinearen Grammatik G gibt es einen NFA M mit $L(G)=L(M)$

> Satz: Sei $\sum$ ein Alphabet und $L\subseteq \sum^*$ eine Sprache. Dann sind äquivalent
> 1. L ist regulär (d.h. von einem DFA akzeptiert)
> 2. L wird von einem NFA akzeptiert
> 3. L ist rechtslinear (d.h. von einer Typ-3 Grammatik erzeugt)

verschiedene Modelle zur Beschreibung regulärer  Sprachen:
- *Rechtslineare Grammatiken*: Verbindung zu Chomsky-Hierarchie, erzeugen Sprachen, wenig geeignet für Entscheidung, ob Wort zu Sprache gehört
- *NFAs*: kompakte Darstellungen von Sprachen, intuitive graphische Darstellung; wenig geeignet für Entscheidung, ob Wort zu Sprache gehört
- *DFAs*:u.U. exponentiell größer als NFA bzw. Grammatik; gut geeignet für Entscheidung, ob Wort zu Sprache gehört

> Definition: Gegeben sei eine Klasse K und ein n-stelliger Operator $\otimes : K^n \rightarrow K$. Man sagt, eine Klasse $K'\subseteq K$ ist unter $\otimes$ abgeschlossen, wenn für beliebige Elemente $k_1,k_2,...,k_n\in K'$ gilt $\otimes (k_1,k_2,...,k_n)\in K'$

> Satz: Wenn $L\subseteq \sum^*$ eine reguläre Sprache ist, dann ist auch $\sum^* \backslash L$ regulär

Beweis: Da L regulär ist, gibt es einen DFA M mit $L(M)=L$. In diesem vertauschen wir die End- und Nicht-Endzustände, d.h. $M'=(Z,\sum ,z_0, \delta, Z\backslash E)$. Dann gilt für $w\in\sum^*$:
$$w\in\sum^* \backslash L \leftrightarrow w\not \in L(M) \leftrightarrow \hat{\delta}(z_0, w)\not \in E \leftrightarrow \hat{\delta}(z_0, w)\in Z\backslash E \leftrightarrow w\in L(M')$$

> Satz: Wenn $L_1$ und $L_2$ reguläre Sprachen sind, dann ist auch $L_1 \cup L_2$ regulär.

Beweis: Es gibt NFAs M für $i=1,2$ mit $L(M_i)=L_i$: $M=(Z_1 \cup Z_2, \sum, S_1\cup S_2, \delta, E_1\cup E_2)$ wobei $\delta(z,a)=\delta_1(z,a) \text{ für } z\in Z_1; \delta_2(z,a) \text{ für } z\in Z_2$

> Satz: Wenn $L_1$ und $L_2$ reguläre Sprachen sind, dann ist auch $L_1 \cap L_2$ regulär.

Beweis: es gilt $L_1 \cap L_2 = \overline{\overline{L_1}\cup \overline{L_2}}$ und die Klasse der regulären Sprache unter Komplement und Vereinigung ist abgeschlossen.

Bemerkung: wird $L_i$ von dem NFA M akzeptiert so existiert ein DFA mit $2^{2 |Z_1| + 2 |Z_2|}$ Zuständen, der $L(M_1)\cap L(M_2)$ akzeptiert. Es gibt eine Konstruktion die mit $|Z_1|*|Z_2|$ Zuständen auskommt.\\
In dieser Konstruktion werden die zwei Automaten miteinander synchronisiert und quasi "parallelgeschaltet". Dies erfolgt durch das Bilden des Kreuzprodukt. Seien $M_i$ NFAs mit $L(M_i)=L_i$. Betrachte den NFA $M=(Z_1 \times Z_2, \sum, S_1 \times S_2, \delta, E_1 \times E_2)$


> Satz: Wenn $L_1$ und $L_2$ reguläre Sprachen sind, dann ist auch $L_1L_2$ regulär

Beweis: Es gibt NFAs $M_i$ mit $L(M_i)=L_i$ o.B.d.A $Z_1\cap Z_2 =\emptyset$. Verknüpfe nun $M_1$ und $M_2$ sequentiell zu einem NFA $M=(Z_1 \cup Z_2, \sum, S,\delta, E_2)$. 

$$S=\begin{cases} S_1 &\quad\text{ für } \epsilon \not = L_1 \\ S_1\cup S_2 &\quad\text{ für } \epsilon \in L_1 \end{cases}$$

$$\delta(z,a)= \begin{cases} 
\delta_2(z,a) &\quad\text{für } z\in Z_2 \\ 
\delta_1(z,a) &\quad\text{für } z\in Z_1 \text{ mit } \delta_1\cap E_1 =\emptyset \\ 
\delta_1(z,a)\cup S_2 &\quad\text{für } z\in Z_1 \text{ mit } E_1 \not = \emptyset \end{cases}$$

> Satz: Wenn L eine reguläre Sprache ist, dann ist auch $L^+$ regulär

Beweis: es gibt einen NFA M mit $L(M)=L$

Betrachte den NFA M' mit $\begin{cases}
\delta(z,a) &\text{ falls } \delta(z,a)\cap E = \varnothing \\
\delta(z,a)\cup S &\text{ sonst } \end{cases}$

Behauptung: für alle $Y\subseteq Z$ und $w\in\sum^+$ gilt $\top{\sigma}(Y,w)=\top{sigma}(Y,w)\cup \bigcup \top{\sigma}(S, u_n)$


> Satz: Wenn L eine reguläre Sprache ist, dann ist auch $L^*$ regulär.

Beweis: Nach dem Lemma zuvor ist $L^+$ regulär. Da auch ${\epsilon}$ regulär ist folgt mit ${\epsilon}\cup L^+ = L^0 \cup \bigcup L^n = L^*$

## Reguläre Ausdrücke
reguläre Ausdrücke erlauben es, die regulären Sprachen kompakt in "Textform" zu beschreiben

> Definition: Die Menge $Reg(\sum)$ der **regulären Ausdrücke über dem Alphabet $\sum$** ist die kleinste Menge mit folgenden Eigenschaften:
> - $\varnothing \in Reg(\sum), \lambda \in Reg(\sum), \sum \subseteq Reg(\sum)$
> - Wenn $\alpha, \beta \in Reg(\sum)$, dann auch $(\alpha * \beta), (\alpha + \beta), (\alpha^*)\in Reg(\sum)$

- für $\alpha * \beta$ schreibt man oft $\alpha\beta$
- für $\alpha + \beta$ schreibt man auch $\alpha|\beta$

Beispiel: $\sum={a,b,c,d}: \lambda ((ab)b) ((a+d)a) ((((ab)a)) + ((ba)b*))$

> Definition: Für einen regulären Ausdruck $\alpha \in Reg(\sum)$ ist die Sprache $L(\alpha)\subseteq \sum^*$ induktiv definiert
$$L(\alpha)=\begin{cases}
\varnothing &\text{ falls } alpha=\not O \\
{\epsilon} &\text{ falls } \alpha = \lambda \\
{a} &\text{ falls } \alpha=a\in \sum \\
L(\beta)\cup L(\gamma) &\text{ falls } \alpha =(\beta + \gamma)\\
L(\beta)L(\gamma) &\text{ falls } \alpha=(\beta*\gamma)\\
(L(\beta))^* &\text{ falls } \alpha=(\beta^*)
\end{cases}$$

Klammern sparen:
- äußere Klammern weglassen
- bei Operatoren auf gleicher Ebene weglassen

Präferenzregel:
- $*$ bindet stärker als $\times$
- $\times$ bindet stärker als $+$

Wo tauchen reguläre Ausdrücke auf:
- Suchen und Ersetzten
- Pattern Matching
- Übersetzung (von Programmiersprachen): Lexikalische Analyse

> Proposition: zu jedem regulären Ausdruck $\gamma$ gibt es einen NFA M mit $L(\gamma)=L(M)$

Beweis: per Induktion über den Aufbau von $\gamma$

> Proposition: zu jedem DFA M gibt es einen regulären Ausdruck $\gamma$ mit $L(M)=L(\gamma)$

Beweis: Sei M ein DFA. Konstruiere einen regulären Ausdruck mit $\gamma$ mit $L(M)=L(\gamma)$. Für ein Wort $w\in \sum^*$ sei $Pref(w)={u\in\sum^* | \exists v:w = uv, \epsilon\not= u\not= w}$ die Menge aller nicht-leeren echten Präfixe von w.

Sei $L\subseteq \sum^*$ eine Sprache, dann sind äquivalent
- L ist regulär, d.h. es gibt einen DFA M mit $L(M)=L$
- es gibt einen NFA M mit $L(M)=L$
- L ist rechtslinear, d.h. es gibt eine rechtslineare Grammatik G mit $L(G)=L$
- Es gibt einen regulären Ausdruck $\gamma$ mit $L(\gamma)=L$

## Zusammenfassung
- Rechtslineare Grammatiken
  - Verbindung zur Chomsky Hierarchie
  - erzeugen Sprachen
  - nicht geeignet, um zu entscheiden, ob ein gegebenes Wort zur Sprache gehört
- NFA
  - erlauben kleine Kompakte Darstellung
  - intuitive graphische Notation
  - nicht geeignet, um zu entscheiden, ob ein gegebenes Wort zur Sprache gehört
- DFA
  - für effiziente Beantwortung der Frage, ob ein Wort zur Sprache gehört
  - sind uU exponentiell größer als NFA
- Reguläre Ausdrücke
  - erlauben kompakte Darstellung in Textform

## Nicht-Reguläre Sprachen
ist vielleicht jede Sprache regulär? Zeige für jede Alphabet $\sum$
1. es gibt nur abzählbar unendlich viele Sprachen über $\sum$, die Sprache einer Grammatik sind
2. Es gibt überabzählbar viele Sprachen über $\sum$

> Lemma: Für jedes Alphabet $\sum$ ist die Menge $\{L(G) | \text{G Grammatik über} \sum\}$ abzählbar unendlich.

$|P(\sum^*)\cap RE|=|RE|=|\N|$

> Satz: Für jedes Alphabet $\sum$ ist die Menge $P(\sum^*)={L|L \text{Sprache über} \sum}$ überabzählbar, d.h. es gibt keine bijektive Funktion $F:\N \rightarrow P(\sum^*)$.

Beweis: Indirekte "Diagonalisierung" auf die bijektive Funktion $F:\N\rightarrow P(\sum^*)$

> Korollar: Für jedes Alphabet $\sum$ existiert eine Sprache L über $\sum$, die von keiner Grammatik G erzeugt wird.

### Konkrete nicht-reguläre Sprachen
Um zu zeigen, dass eine konkrete Sprache L regulär ist, kann man
- einen NFA M angeben mit $L(M)=L$, oder
- eine rechtslineare Grammatik G angeben mit $L(G)=L$, oder
- einen regulären Ausdruck $\gamma$ angeben mit $L(\gamma)=L$, oder
- zeigen, dass $L=L_1 \cap L_2$ ist und $L_1$ und $L_2$ regulär sind, oder
- ...

### Pumping Lemma (auswendig lernen!)
Wenn L eine reguläre Sprache ist, dann gibt es $n\leq 1$ derart, dass für alle $x\in L$ mit $|x|\geq n$ gilt: es gibt Wörter $u,v,w \in \sum^*$ mit:
1. $x=uvw$
2. $|uv|\leq n$
3. $|v|\geq 1$
4. $uv^i w\in L$ für alle $i\geq 0$

Dieses Lemma spricht nicht über Automaten, sondern nur über die Eigenschaften der Sprache. Es ist geeignet, Aussagen über Nicht-Regularität zu machen. Dabei ist es aber nur eine notwendige Bedingung. Es kann nicht genutzt werden, um die Regularität einer Sprache L zu zeigen.

### Myhill-Nerode Äquivalenz
Ein zweites Verfahren um Nicht-Regularität zu zeigen. Dieses kann auch genutzt werden um Regularität zu beweisen. 

> Definition Myhill-Nerode-Äquivalenz: Für eine Sprache $L\subseteq \sum^*$ definieren wir eine binäre Relation $R_L \subseteq \sum^* \times \sum^*$ wie folgt: Für alle $x,y\in \sum^*$ setze $(x,y)\in R_L$ genau dann, wenn $\forall z \in \sum^* :(xy\in L \leftrightarrow yz \in L)$ gilt. Wir schreiben hierfür auch $x R_L y$.

Beispiel: Gegeben sei die Sprache $L=\{ w\in \{a,b\}^*: |w|_a gerade\}$. Seien $x,z\in \{a,b\}^*$. Betrachte zwei Fälle:
- $|z|_a$ gerade: $xz\in L \leftrightarrow |xz|_a$ gerade $\leftrightarrow |x|_a$ gerade
- $|z|_a$ ungerade: $xz\in L \leftrightarrow |xz|_a$ gerade $\leftrightarrow |x|_a$ ungerade
also: $x R_L y \leftrightarrow |x|_a \equiv |y|_a$

> Lemma: Sei $L \subseteq \sum^*$ eine Sprache
> - die binäre Relation $R_L$ ist eine Äquivalenzrelation
> - aus $x R_L y$ und $a\in\sum$ folgt $xa R_L ya$

> Definition: Für eine Sprache L und ein Wort $x\in \sum^*$ ist $[x]_L=\{y\in\sum^* | x R_L y \}$ die Äquivalenzklasse von x. Ist L klar, so schreiben wir einfacher $[x]$.

Beispiel Äquivalentklassen für $R_L$ mit der Sprache $L=\sum^*\{abc\}$
- $[\epsilon]=\{w\in\{a,b,c\}^* | \text{kein nichtleerer Präfix von abc ist Suffix von w} \}$
- $[a]=\{w\in\{a,b,c\}^* | \text{w endet auf a}\}$
- $[ab]=\{w\in\{a,b,c\}^* | \text{w endet auf ab}\}$
- $[abc]=\{w\in\{a,b,c\}^* | \text{w endet auf abc}\}$


Der Index $index(R)$ von R ist die Anzahl der Äquivalenzklassen von R: $index(R)=|\{[x]:x \in A \} | \in \N \cup \{\infty\}$

> Satz von Myhill-Nerode: Sei L eine Sprache. L ist regulär $\leftrightarrow index(R_L)< \infty$
(d.h. nur wenn die Myhill-Nerode-Äquivalenz endliche Klassen hat)

Beweis:
- "$Rightarrow$": Sei L regulär -> es gibt DFA M mit $L(M)=L$...
- "$Leftarrow$": sei $index(R_L)< \infty$ -> Definiere einen DFA $M_L=(\{[x_1],...,[x_n]\},\sum,[\epsilon],\sigma,\{[w]|w\in L\})$
  

## Minimalautomat
Es gibt bekanntlich sehr verschiedene endliche Beschreibungen einer regulären Sprache. Diese können ineinander übersetzt werden aber eine einzelne Sprache kann auch durch verschiedene DFAs dargestellt werden.

Gibt es einen "besten DFA" bzw was macht einen Automaten besser? D.h. gibt es einen DFA mit möglichst wenig Zuständen?

> Definition: Ein DFA M heißt reduziert, wenn es für jeden Zustand $z \in Z$ ein Wort $x_z\in \sum^*$ gibt mit $\hat{\sigma}(l, x_z)=z$

Wenn in einem DFA M aus Startzustand X und Y dieselben Sprachen akzeptiert werden, heißen diese "erkennungsäquivalent" und werden "verschmolzen" (es entsteht M'). M und M' akzeptieren diesselbe Sprache. Sind keine Zustände mehr erkennungsäquivalent können keine weiteren verschmolzen werden und es gibt keinen DFA der mit weniger Zuständen L(M) akzeptiert

> Definition: Sei M ein DFA. Zwei Zustände $z,z'\in Z$ heißen erkennungsäquivalent (in Zeichen $z\equiv z'$) wenn für jedes Wort $w\in \sum^*$ gilt: $\hat{\sigma}(z,w)\in E \leftrightarrow \hat{\sigma}(z',w)\in E$

> Lemma: Sei M ein DFA, $z,z'\in Z$ und $a\in \sum$:
> - $\equiv$ ist eine Äquivalenzrelation auf Z
> - $z\equiv z'$ impliziert $(z\in E \leftrightarrow z'\in E)$
> - $z\equiv z'$ impliziert $\hat{\sigma}(z,a)\equiv \sigma(z',a)$

> Definition: Sei M ein DFA. Dann ist $M'=(Z_{\equiv},\sum, [z_0],\sigma', E')$ mit
> - $\sigma'([z],a)=[\sigma (z,a)]$ für $z\in Z$ und $a\in \sum$ und
> - $E'=\{[z]|z\in E\}
> der Quotient von M bzgl $\equiv$
(es wird nicht mehr jeder einzelne Fall betrachtet sondern "ganze Gruppen"; Bsp Sitz->Reihe)

> Lemma: Ist M ein DFA und M' sein Quotient bzgl. $\equiv$, so ist M' ein DFA mit $L(M)=L(M')$

Es bleibt zu zeigen, dass $\sigma'$ wohldefiniert ist $\rightarrow z\equiv z' \rightarrow \sigma (z,a)\equiv \sigma (z',a) \rightarrow [\sigma (z,a)]=[\sigma (z',a)]$. Also ist M' tatsächlich ein DFA.

> Definition: Seien $M_i$ DFAs (für $i\in\{1,2\}$) und $f:Z_1 \rightarrow Z_2$ eine Funktion. Dann ist f ein Homomorphismus von $M_1$ auf $M_2$, falls gilt:
> - $f(l_1)=l_2$
> - $f(\sigma_1(z,a))=\sigma_2(f(z),a)$ für alle $z\in Z_1$ und $a\in \sum$
> - $z\in E_1 \leftrightarrow f(z)\in E_2$ für alle $z\in Z_1$ (bildet Endzustände aufeinander ab)

> Satz: Seien $M_i$ reduzierte DFAs mit $L(M_1)=L(M_2)$. Sei weiter $M_2'$ der Quotient von $M_2$ bzgl $\equiv$. Dann existiert ein surjektiver Homomorphismus von $M_1$ auf $M_2'$

- die Abbildung f ist surjektiv (auf $M_2$). Und damit ist $M_2 < M_1$
- die Abbildung f ist ein Homomorphismus

> Satz: Seien $M_1$ und $M_2$ reduzierte DFAs mit $L(M_1)=L(M_2)$. Sei $M_1'$ der Quotient von M bzgl $\equiv$
> - $M_2$ hat wenigstens so viele Zustände wie $M_1'$
> - Hat $M_2$ genauso viele Zustände wie $M_1'$, so sind $M_2$ und $M_1'$ bis auf Umbennenung der Zustände identisch (sie sind Isomorph)

> Folgerung: Seien $M_1$ und $M_2$ reduzierte DFAs mit $L(M_1)=L(M_2)$. Seien $M_1'$ und $M_2'$ die Quotienten bzgl $\equiv$. Dann sind $M_1'$ und $M_2'$ isomorph, d.h. für jede reguläre Sprache gibt es (bis auf Umbenennung der Zustände) genau einen minimalen DFA

Um den minimalen DFA zu erhalten bildet man den Quotienten eines beliebigen zur Sprache passenden DFA.

> Satz: Für einen reduzierten DFA M wird ein Paar ${z,z'}\subseteq Z$ mit $z\not = z'$ genau dann durch den Markierungsalgorithmus markiert werden, wenn $z\not \equiv z'$

### Algorithmus Minimalautomat
Eingabe: reduzierter DFA M\\
Ausgabe: Menge der Paare erkennungsäquivalenter Zustände
1. Stelle eine Tabelle aller ungeordneten Zustandspaare $\{z,z'\}$ mit $z\not = z'$ auf
2. Markiere alle Paare $\{z,z'\}$ mit $z\in E$ und $z'\not\in E$
3. Markiere ein beliebiges unmarkiertes Paar $\{z,z'\}$, für das es ein $a\in\sum$ gibt, sodass $\{\sigma(z,a),\sigma(z',a)\}$ bereits markiert ist (falls möglich)
4. Wiederhole den vorherigen Schritt, bis sich keine Änderung in der Tabelle mehr ergibt

> Satz: Für einen gegebenen reduzierten DFA M markiert der Minimierungsalgorithmus ein $\{z,z'\}(z,z'\in Z, z\not=z')$ genau dann, wenn $z\not\equiv z'$

## Entscheidbarkeit
Fragestellungen/Probleme für reguläre Sprachen

### Wortproblem
Gilt $w\in L$ für eine gegebene reguläre Sprache L und $w\in\sum^*$

Eingabe: DFA M und $w\in\sum^*$

Verfahren: Verfolge die Zustandsübergänge von M, die durch die Symbole $a_1,...,a_n$ vorgegeben sind.


### Leerheitsproblem
Gilt $L=\varnothing$ für eine gegebene reguläre Sprache L?

Eingabe: NFA M

Verfahren: Sei $G=(Z,\rightarrow)$ der gerichtete Graph mit $z\rightarrow z' \leftrightarrow \exists a \in \sum: z'\in\sigma(z,a)$. Dann gilt $L(M)\not =\varnothing$ genau dann, wenn es in dem Graphen G einen Pfad von einem Knoten aus S zu einem Knoten aus E gibt. Dies kann zB mit dem Algorithmus von Dijkstra entschieden werden.


### Endlichkeitsproblem
Ist eine gegebene reguläre Sprache L endlich?

Eingabe: NFA M

Verfahren: Sei $G=(Z,\rightarrow)$ wieder der gerichtete Graph mit $z\rightarrow z' \leftrightarrow \exists a \in\sum:z'\in\sigma(z,a)$. Dann gilt L(M) ist genau dann unendlich, wenn es $z\in Z,z_0\in S$ und $z_1\in E$ gibt mit $z_0\rightarrow^* z \rightarrow^+ z \rightarrow^* z_1$. D.h. z liegt auf einem Zyklus, ist von einem Startzustand aus erreichbar und von z kann ein Endzustand erreicht werden. Dies kann wieder mit dem Algorithmus von Dijkstra entschieden werden.

### Schnittproblem
Gilt $L_1\cap L_2=\varnothing$ für gegebene reguläre $L_1,L_2$?

Eingabe: NFAs $M_1$ und $M_2$

Verfahren: Konstruiere aus $M_1$ und $M_2$ einen NFA M mit $L(M)=L(M_1)\cap L(M_2)$. Teste ob $L(M)=\varnothing$

### Inklusionsproblem
Gilt $L_1 \subseteq L_2$ für gegebene reguläre $L_1,L_2$?

Eingabe: NFAs $M_1$ und $M_2$

Verfahren: Aus $M_1$ und $M_2$ kann ein NFA M mit $L(M)=\bar{L(M_2)}\cap L(M_1)$ konstruieren. Es gilt $L(M_1)\subseteq L(M_2)$ genau dann, wenn $L(M)=\varnothing$.

### Äquivalenzproblem
Gilt $L_1=L_2$ für gegebene reguläre $L_1,L_2$?

Eingabe: NFAs $M_1$ und $M_2$

Verfahren 1: es gilt $L(M_1)=L(M_2)$ genau dann, wenn $L(M_1)\subseteq L(M_2)$ und $L(M_2)\subseteq L(M_1)$.

Verfahren 2: bestimme zu $M_i (i\in\{1,2\})$ den äquivalenten minimalen DFA $N_i$. Dann gilt $L(M_1)=L(M_2)$ genau dann, wenn $N_1$ und $N_2$ isomorph sind (d.h. sie können durch Umbennenung der Zustände ineinander überführt werden).

### Effizientbetrachtung
Die Komplexität der oben beschriebenen Verfahren sehr unterschiedlich ausfallen. Bei Eingabe der regulären Sprache als NFA bzw DFA ergeben sich die folgenden Zeitschranken:

| Problem | NFA | DFA |
| Wort~   | polynomiell | linear |
| Leerheits~| polynomiell | polynomiell |
| Endlichkeits~ | polynomiell | polynomiell |
| Schnitt~ | polynomiell | polynomiell |
| Inklusions~ | exponentiell | polynomiell |
| Äquivalenz~ | exponentiell | polynomiell |

Es spricht viel dafür, dass die exponentiellen Zeitschranken nicht durch polynomielle ersetzt werden können.

Anwendung: Verifikation
- zwei Prozesse 1 und 2 wollen auf eine gemeinsame Ressource zugreifen
- jeder Prozess hat einen kritischen Bereich in dem auf die Ressource zugegriffen wird. Nur ein Prozess darf sich im kritischen Bereich befinden
- es stehen gemeinsame Variablen zur Verfügung über die sich die Prozesse synchronisieren können
- wir möchten zeigen,d ass der wechselseitige Ausschluss gewährleistet ist und eine gewisse Fairnessbedingung eingehalten wird
- betrachtung der Prozesse als Wort
  - jeder Ablauf eines Prozesses ist ein Wort, die Menge der Abläufe ist eine Sprache
  - ebenso ist die Menge der Abläufe des Gesamtsystems eine Sprache
  - auch die Menge der erlaubten/verbotenen Abläufe ist eine Sprache
- damit ist das Inklusionsproblem/Schnittproblem $L_{Sys}\subseteq L_{Spec}$ zu lösen

### Pumping Lemma mit Alphabet aus einem Zeichen 
$\sum=\{a\}$, $L(M)=\{a\} regulär \rightarrow \exists n \geq 1 \forall z\in Z(M)$ mit $|z|\geq n$, z.B. $n=3$

Bei geschickter Wahl von n ist das Pumping Lemma nicht voll ausführbar und ist korrekt.
Wenn n endlich ist gibt es ein z das Länger ist.

(Sind alle endlichen Sprachen regulär? Ja, jede Sprache ist aufgebaut aus der verknüpfung von einelementigen Sprachen; diese selbst sind regulär.)

### Spielschema oder anderes Schema in Prüfung gefirdert
kann noch keine aussage dazu treffen, Klausur existiert noch nicht. Jedoch grundsätzlich: es wird auswendig gelernt! Sätze/Definitionen etc werden mit Lückentext abgefragt. Ein großer Teil der Aufgaben orientiert sich an den Übungsaufgaben.

### Produktbildung von zwei regulären Sprachen. Wenn die erste Sprache als Startzustand da leere Wort enthält, muss man den Startzustand der zweiten Sprache beibehalten?
Bei Automaten die nicht das leere Wort akzeptieren unter umständen, bei Automaten die kein leeres Wort akzeptieren nicht.

- es gibt (in dieser Vorlesung) keine unendlich langen Wörter

# Kontextfreie Sprachen
bei Kontext-freien Grammatiken haben alle Produktionen die Form $A\rightarrow w$ mit $A\in V$ und $w\in (V\cup \sum)^*$.

Anwendung kontext-freier Sprachen: Beschreibung der Syntax von Programmiersprachen (besonders höheren Sprachen). Viele der Techniken daher interessant für den Compilerbau

Bemerkung: die natürliche Sprache hat viele kontext-freie Bestandteile, ist aber nicht wirklich kontext-frei.

## Ableitungsbäume
Ein Ableitungsbaum wird aus den Ableitungen einer Grammatik gebildet. Die Blätter (von links nach rechts) bilden immer den letzten Abbildungsschritt. Unterschiedliche Ableitungen können unterschiedliche Bäume konstruieren während diese das gleiche Wort ableiten.

> Definition: Sei G eine kontext-freie Grammatik und $X\in V\cup \sum$. Ein X-Ableitungsbaum ist ein gerichteter, geordneter Baum T mit Wurzel, dessen Knoten mit Elementen von $V\cup\sum\cup\{\epsilon\}$ beschriftet sind, wobei:
> - die Wurzel mit X beschriftet ist
> - Knoten $v$ mit $a\in\sum\cup\{\epsilon\}$ beschriftet $\Rightarrow$ v ist ein Blatt
> - Knoten $v$ mit $A\in V$ beschriftet und kein Blatt $\Rightarrow$
>   - es gibt eine Produktion $A\rightarrow X_1...X_r$ mit $X_1...X_r\in\sum\cup V$ $(r\geq 1)$ sodass die Nachfolgerknoten von $v$ mit $X_1,X_2,...,X_r$ beschriftet sind
>   - oder es gibt Produktion $A\rightarrow \epsilon$ und $v$ hat genau einen Nachfolger; dieser ist mit $\epsilon$ beschriftet
> - Das Blattwort $\alpha(T)$ des X-Ableitungsbaumes T erhält man, indem man die Beschriftungen der Blätter von links nach rechts betrachtet. Ein Ableitungsbaum ist ein S-Ableitungsbaum.
> - ein X-Ableitungsbaum ist vollständig, wenn seine Blätter mit Elementen von $\sum\cup\{\epsilon\}$ beschriftet sind.

> Lemma: Sei $G$ eine kontext-freie Grammatik, $X\in V\cup\sum, w\in(V\bigcup\sum)^*$. Dann sind äquivalent:
> - $X\rightarrow^* w$
> - es gibt einen X-Ableitungsbaum T mit $w=\alpha(T)$

Die Ableitung innerhalb eines Ableitungsbaumes ist die Verkettung der Ableitungen seiner Unterbäume. $\alpha(T)=\alpha(X_1)\cap \alpha(X_2)\cap...\cap\alpha(X_3)=...$

## Linksableitung
Zu jedem Ableitungsbaum kann es eine oder mehrere Ableitungen geben. 
> Definition: Eine Ableitung heißt Linksableitung wenn in jedem Schritt das am weitesten links stehende Nichtterminal ersetzt wird.

Analog werden Rechtsableitungen definiert.

Ableitungsbäume und Linksableitungen für w entsprechen einander eineindeutig, genauer:
> Satz: Die Konstruktion ist eine Bijektion der Menge der Linksableitungen von Wörtern aus $\sum^*$ auf die Menge der vollständigen Ableitungsbäume.

Aus Linksableitungen (nicht-Linksableitungen) können auch Rechtsableitungen erzeugt werden (und umgekehrt) ohne die Ableitung zu verändern.

Es gibt auch Wörter, mit verschiedenen Linksableitungen (und damit unterschiedlichen Ableitungsbäumen). Da der Ableitungsbaum Strukturinformationen über das Wort wiedergibt ist dies nicht erwünscht.
> Definition: Eine Kontextfreie Grammatik G heißt mehrdeutig, wenn es zwei verschiedene vollständige Ableitungsbäume $T$ und $T'$ gibt mit $\alpha(T)=\alpha(T')$.
> Sonst heißt G eindeutig, d.h. G ist eindeutig wenn jedes Wort $w\in L(G)$ genau eine Ableitung besitzt.
> Eine Kontextfreie Sprache heißt inhärent mehrdeutig, wenn jede kontextfreie Grammatik mit $L=L(G)$ mehrdeutig ist

## kontextfreie Sprachen sind kontext-sensitiv
> Lemma: aus einer kontextfreien Grammatik G kann eine kontextsensitive und gleichzeitig kontextfreie Grammatik G' berechnet werden mit $L(G)=L(G')$

Sprachen: Regulär < Kontextfrei < Kontextsensitiv < RE < alle

> Folgerung: Es gibt einen Algorithmus, der als Eingabe eine Typ-2-Grammatik G und ein Wort $w\in\sum^*$ bekommt und nach endlicher Zeit entscheidet, ob $w\in L(G)$ gilt.

## Chomsky Normalform
> Definition: Eine kontextfreie Grammatik g ist in Chomsky Normalform, falls
> - alle Produktionen von G die Form $A\rightarrow AB$ oder $A\rightarrow a$ haben
> - oder alle Produktionen von G die Form $A\rightarrow BC$ oder $A\rightarrow a$ oder $S\rightarrow\epsilon$ haben und S nie auf der rechten Seite einer Produktion vorkommt.

Beobachtung: Sei G in Chomsky Normalform und T ein Ableitungsbaum eines Wortes w der Länge n. Dann gilt:
- jeder innere Knoten hat genau 2 mit Nichtterminalen beschriftete Kinder oder genau ein mit einem Terminal beschriftetes Kind und
- es gibt n Blätter
Also hat T genau $3n-1$ viele Knoten

> Satz: Zu jeder kontextfreien Grammatik gibt es eine Grammatik G' in Chomsky Normalform mit $L(G)=L(G')$

Mit dieser Grammatik weiß man genau die Länge die man benötigt um ein Wort abzuleiten

## Der Cocke-Younger-Kasami- oder CYK-Algorithmus
Sei G kontextfreie Grammatik.  Gesucht ist ein Algorithmus mit dessen Hilfe wir entscheiden können, ob ein gegebenes Wort zu L(G) gehört.

1. Versuch sei kontextsensitiv, dann werden diejenigen Wörter berechnet, die sich in < w vielen schritten ableiten lassen und getestet ob w darunter ist. Dieses Verfahren hat also exponentielle Laufzeit
2. heutiges Ziel: polynomiieller Algorithmus; Vorraussetzung: Die grammatik ist in Chomsky Normalform

Idee: Gegeben sei ein Wort $w\in\sum^*$. Wir wollen feststellen, aus welchen Nichtterminalen es abgeleitet werden kann.
- Möglichkeit 1: $w=a\in\sum$, d.h. w besteht aus einem einzigen Alphabetsymbol. Dann kann w nur aus denjenigen Nichtterminalen A abgeleitet werden, für die es eine Produktion $A\rightarrow a4 gibt.
- Möglichkeit 2: $w=a_1...a_n$ mit $n\geq 2$. Zunächst muss eine Produktion $A\rightarrow BC$ angewandt werden, dann muss  ein Teil $a_1...a_k$ des Wortes aus B und der andere Teil $a_{k+1}...a_n$ des Wortes aus C abgeleitet werden. Es ist jedoch nicht klar, wo das Wort w geteilt werden musss, d.h. wie groß die Position k ist! Probiere alle möglichen k's durch.

Um Mehraufwand zu vermeiden, verwenden wir die Methode der dynamischen Programmierung, d.h.
- berechne zunächst alle Nichtterminale aus denen sich Faktoren der Länge 1 ableiten lassen
- berechne dann alle Nichtterminale, aus denen sich Faktoren der Länge 2 (3,4,...) ableiten lassen
- zuletzt berechne alle Nichtterminale, aus denen sich w ableiten lässt
Das Wort w liegt genau dann in der von der Grammatik erzeugten Sprache, wenn S sich unter diesen Nichtterminalen befindet.

Komplexität des CYK-Algorithmus:\\
sei $n=|w|$ die Länge dees Wortes, das untersucht wird. Die größe der Grammatik wird als konstant angesehen. Dann gilt:
- $O(n^2)$ Tabellenfelder müssen ausgefüllt werden
- für das Ausfüllen jedes Tablellenfeldes müssen höchstens n Paare anderer Felder betrachtet werden
Daher ergibt sich insgesamt als Zeitkomplexität $O(n^3)$.


## Kellerautomaten
um ein Automatenmodell für Kontextfreie Sprachen zu erhalten
- führen wir daher einen keller oder Pushdown-Speicher ein, auf dem sich eine beliebig lange Sequenz von Zeichen befinden darf
- beim Einlesen eines neuen Zeichens wird das oberste Zeichen des Kellers gelesen und durch eine (evtl. leere) Sequenz von Zeichen ersetzt. An anderen Stellen kann der Keller nicht gelesen/geändert werden
- im Rechnermodell
  - Art des Speicherzugriffs: Kellerspeicher
  - Art der Steuereinheit: nichtdeterministisch
- der Keller
  - Zu beginn einer jeden Berechnung enhält der Keller genau das Kellerinitialisierungszeichen #
  - der Keller ist nicht beschränkt und kann beliebig wachsen, es gibt aleo unendlich viele Mögliche Kellerinhalte. Mit anderen Worten: im gegensatz zu endlichen Automaten haben Kellerautomaten unendlich viele interne "Zustände"
  - die von uns betrachteten Kellerautomaten akzeptieren immer mit leerem Keller (in diesem Fall gibt es auch keine Übergangsmöglichkeiten mehr).

(Pushdown: nur oben etwas darauflegen, wenn etwas weggenommen wird ist es immer auf derselben Höhe. Bsp Mensadamen Teller)

> Definition: Ein Kellerautomat M ist ein 6-Tupel $M=(Z,\sum,\Gamma, z_0, \delta, \#)$, wobei
> - Z die endliche Menge der Zustände
> - $\sum$ das Eingabealphabet
> - $\Gamma$ das Kelleralphabet
> - $z_o\in Z$ der Startzustand
> - $\delta: Z \times (\sum \cup \{\epsilon\})\times \Gamma \rightarrow P_{\epsilon}Z\times\Gamma^*)$ die Überführungsfunktion

Bemerkung: $P_{\epsilon}Z\times\Gamma^*)$ bezeichnet die Menge aller endlichen Teilmengen von $Z\times\Gamma^*$

Abkürzungen: PDA (pushdown automaton) oder NPDA (nondeterministic pushown automaton)

> Definition: Ein **Konfiguration** eines PDA ist ein Tripel $k\in Z \times \sum^* \times \Gamma^*$
- $z\in Z$ ist der aktuelle Zustand
- $w\in\sum$ ist der noch zu lesende Teil der Eingabe
- $\gamma \in \Gamma^*$ ist der aktuelle Kellerinhalt. Dabei steht das oberste Kellerzeichen ganz links
 
Übergänge zwischen Konfigurationen ergeben sich aus der Überführungsfunktion $\delta$

> Definition: Seien $\gamma\in\Gamma^*, A_1B_1,...,B_k\in\Gamma, w, w'\in\sum^*$ und $z,z'\in Z$. Dann gilt $(z,w,A\gamma)\rightarrow (z',w', B_1...B_{k\gamma})$ genau dann, wenn es $a\in\sum \cup\{\epsilon\}$ gibt mit $w=aw'$ und $(z',B_1...B_k)\in\delta(z,a,A)$

> Definition: Sei M ein PDA. Dann ist die von M **akzeptierte Sprache**: $L(M)=\{x\in\sum^* | \text{es gibt } z\in Z $\text{mit} (z_0, x, \#) [...] ^*(z,\epsilon, \epsilon)\}$

Übergänge zwischen Konfigurationen ergeben sich aus der Überführungsfunktion $\delta$:
- seien $\gamma\in\Gamma, A,B_1...B_2\in\Gamma, w,w'\in\sum^*, z,z'\in Z$. Dann gilt $(z,w,A\gamma)\vdash (z',w',B_1...B_{k\gamma})$ genau dann, wenn es $a\in\sum\cup\{\epsilon\}$ gibt mit $w=aw'$ und $(z',B_1...B_k)\in\delta(z,a,A)$
- gilt $a\in\sum$ so wird ein Zeichen der Eingabe gelesen. Falls $a=\epsilon$ gilt, so nicht
- $(z',B_1...B_k)\in\delta(z,a,A)$
  - Zeichen a wird gelesen
  - Zustand ändert sich von z nach z'
  - Symbol A wird durch mehrere neue Symbole ersetzt
- $(z',BA)\in\delta(z,a,A)$
  - Zeichen a wird gelesen
  - Zustand ändert sich von z nach z'
  - Symbol B wird zusätzlich auf den Keller gelegt
- $(z',B)\in\delta(z,a,A)$
  - Zeichen a wird gelesen
  - Zustand ändert sich von z nach z'
  - Symbol A auf dem Keller wird durch B ersetzt
- $(z',A)\in\delta(z,a,A)$
  - Zeichen a wird gelesen
  - Zustand ändert sich von z nach z'
  - Keller bleibt unverändert
- $(z',\epsilon)\in\delta(z,a,A)$
  - Zeichen a wird gelesen
  - Zustand ändert sich von z nach z'
  - Symbol A wird vom Keller gelöscht

> Definition: Sei M ein PDA. Dann ist die von M akzeptierte Sprache $L(M)=\{x\in\sum^* | \text{ es gibt } z\in Z \text{ mit } (z_0,x,\#)\vdash^* (z,\epsilon,\epsilon)\}$

D.h. die akzeptierte Sprache enthält diejenigen Wörter, mit deren Hilfe es möglich ist den Keller vollständig zu leeren. Da Kellerautomaten jedoch nicht-deterministisch sind, kann es auch Berechnungen für dieses Wort geben, die den Keller nicht leeren.

Idee: statt auf das Zeichen \$ zu warten, kann sich der Automat jederzeit nicht-deterministisch entscheiden, in den Zustand $z_2$(=Keller abbauen) überzugehen (d.h. eine Konfiguration kann mehrere Nachfolgerkonfigurationen haben).

## die Greibach-Normalform
Wir haben als nächstes zu zeigen, dass jede kontextfreie Sprache von einem PDA akzeptiert werden kann. Hierzu wandeln wir die kontextfreie Grammatik zunächst in eine Grammatik in Greibach Normalform um
> Definition: eine kontextfreie Grammatik G ist in **Greibach Normalform** falls alle Produktionen aus P folgende Form haben: $A\rightarrow aB_1B_2...B_k$, mit $k\in \N$, $A,B_1,...,B_k\in V$ und $a\in \sum$
Die Greibach Normalform garantiert, dass bei jedem Ableitungsschritt genau ein Alphabetsymbol entsteht.

> Satz: aus einer kontextfreien Grammatik G kann eine kontextfreie Grammatik G' in Greibach Normalform berechnetwerden mit $L(G')=L(G)\ \{\epsilon\}$.

## Von Grammatiken zu PDAs
Konstruktion: Sei G eine kontextfreie Grammatik in Greibach Normalform. Konstruiere den PDA $M_G$:
- $Z=\{l\}$ es gibt nur einen Zustand
- $\Gamma = V$ die Nichtterminalen der Grammatik bilden das Kelleralphabet
- $\delta(l,a,A)=\{(l,B_1...B_k) | (A\rightarrow aB_1...B_k) \in P\}$ für $a\in\sum, A\in V$ und $\delta(l,\epsilon,A)=\varnothing$ für $A\in V$ es gibt keine $\epsilon$-Transition
- $\#=S$ das Kellerinitialisierungssymbol ist das Startsymbol der Grammatik

> Lemma: $L(G)\subseteq L(M_G)$ und $L(M_G)\supseteq L(G)$, es folgt $L(M_G)=L(G)$

> Jede kontextfreie Sprache L ist Sprache eines PDA M mit nur einem Zustand. Gilt $\epsilon\not\in L$, so werden keine $\epsilon$-Transitionen benötigt

Sei L kontextfrei. Dann existiert eine Grammatik G in Greibach-Normalform mit $L(G)=L\backslash \{\epsilon\}$. Nach den beiden gezeigten Lemmata existiert eine PDA M mit einem Zustand, ohne $\epsilon$-Transitionen und mit $L(M)=L(G)=L\backslash\{\epsilon\}$. Gilt $\epsilon\not\in L$, so ist Proposition bewiesen.

Beispiel: 
G hat die Regeln $S\rightarrow 0SES | 0ES | 0SE | 0E$ und $E\rightarrow 1$
| Linksableitung | PDA Berechnung | Regelbildung |
| -- | -- | -- |
| $S\Rightarrow 0SE$    | $(\iota, 001011, S) \vdash (\iota, 01011, SE)$ | $(\iota, SE)\in\delta(\iota, 0, S)$ |
| $S\Rightarrow 00ESE$  | $\vdash (\iota,1011, ESE)$  | $(\iota, ES)\in\delta(\iota, 0, S)$       |
| $S\Rightarrow 001SE$  | $\vdash (\iota, 011, SE)$   | $(\iota, \epsilon)\in\delta(\iota, 1,E)$  |
| $S\Rightarrow 0010EE$ | $\vdash (\iota, 11, EE)$    | $(\iota, E)\in\delta(\iota, 0, S)$ |
| $S\Rightarrow 00101E$ | $\vdash (\iota, 1, E)$      | $(\iota, \epsilon)\in\delta(\iota,1,E)$ |
| $S\Rightarrow 001011$ | $\vdash (\iota, \epsilon, \epsilon)$ | $(\iota,\epsilon)\in\delta(\iota, 1, E)$ |

- die vorgestellte Methode heißt LL-Parsing: Berechnung des PDA entsprechen Linksableitung und Wort wird von links nach rechts gelesen oder Top-Down-Parsing: Ableitungsbaum wird an der Wurzel beginnend erzeugt
- aus Grammatik Regeln $A\rightarrow aU | aV$ entsteht der Nichtdeterminisumus. LL(1)-Grammatiken enthalten keine solche Regeln, sodass $M_G$ deterministisch wird
- allgemein: in LL(k)-Grammatiken legen die nächsten k zu lesenden Buchstaben fest, welche Regel angewant wird - auch dann kann man einen deterministischen PDAs konstruieren
- LR-Parsing oder Bottom-Up-Parsing sind alternative Methoden, einen PDA aus einer kontextfreien Grammatik zu konstruieren, auch LR(k)-Grammatiken führen zu deterministischen PDAs


## Von PDAs zu Grammatiken
Ziel/Idee: kontextfreie Grammatik G, so dass für alle $w\in\sum^*$: $(i,w,A,)\vdash^*(j,\epsilon, \epsilon)$ gdw $_iA_j \Rightarrow w$

Konstruktion: Sei M ein PDA. Konstruiere die kontextfreie Grammatik $G_M=(V,\sum,P,S)$:
- $V=\{S\}\cup (Z\times\Gamma\times Z)$
- folgende Produktionen
  - $S\rightarrow (\iota, \#, z)$ für alle $z \in Z$
  - $(z_0,A,z_{k+1})\rightarrow a(z_1,B_1,z_2)(z_2,B_2,z_3)...(z_k,B_k,z_{k+1})$ f.a. $z_0\in Z, A\in\Gamma,a\in\sum\cup\{\epsilon\}, (z_1,B_1B_2...B_k)\in\delta(z_0,a,A)$ und $z_2,...,z_{k+1}\in Z$

> Lemma: Für alle $z,z'\in Z,A\in\Gamma$ und $w\in\sum^*$ gilt $(z,w,A)\vdash^*(z',\epsilon,\epsilon)\Rightarrow (z,A,z')\Rightarrow w$

> Ist M ein PDA, so ist L(M) kontextfrei

> Satz: Sei L eine Sprache. Dann sind äquivalent
> - L ist kontextfrei
> - es gibt einen PDA M mit $L(M)=L$
> - es gibt einen PDA M mit nur einem Zustand und $L(M)=L$. Gilt $\epsilon\not\in L$, so sind diese Aussagen äquivalent zu
> - es gibt einen PDA M mit nur einem Zustand und ohne eine $\epsilon$-Transitionen, so dass $L(M)=L$ gilt

## PDAs mit Endzuständen
> Definition: Ein Kellerautomat mit Endzuständen oder PDAE ist ein 7-Tupel M, wobei $(Z,\sum,\Gamma, \iota, \delta, \#)$ ein PDa und $E\subseteq Z$ eine Menge von Endzuständen ist

> Definition: Sei M ein PDAE. Die von M akzeptierte Sprache ist $L(M)=\{w\in\sum^* | \text{es gibt } e\in E \text{ und } \gamma\in\Gamma^* \text{ mit } (\iota, w,\#)\vdash^* (e,\epsilon,\gamma)\}$

PDAEs akzeptieren also so, wie es NFAs tun: Der Inhalt des Kellers nach dem kompletten Lesen der Eingabe ist irrelevant, es kommt nur auf den erreichten Zustand an.

> Lemma: Jede kontextfreie Sprache wird von einem PDAE akzeptiert

> Lemma: Ist M ein PDAE, so wird L(M) von einem PDA akzeptiert, ist also kontextfrei

> Satz: Eine Sprache L ist genau dann kontextfrei, wenn sie von einem PDAE akzeptiert wird

> Satz: Seien L eine kontextfreie und R eine reguläre Sprache. Dann ist $L\cap R$ kontextfrei

## Deterministisch kontextfreie Sprachen
> Definition: ein deterministischer Kellerautomat oder DPDA ist ein PDAE M, so dass für alle $z\in Z, a\in\sum, A\in\Gamma$ gilt: $|\delta(z,a,A)|+|\delta(z,\epsilon,A)|\leq 1$.

> Definition: eine Sprache L ist deterministisch kontextfrei, wenn es einen deterministischen Kellerautomaten M gibt mit $L(M)=L$

- Ziel: ist $L\subseteq \sum^*$ deterministisch kontextfrei, so auch $\sum^*\backslash L$\\
- Beweisidee: vertausche die akzeptierenden und die nichtakzeptierenden Zustände\\
- Problem: es kann Wörter w geben, die vom DPDA M nicht vollständig gelesen werden, weil
    - der Keller leer ist, bevor das Eingabewort vollständig gelesen wurde
    - es keine passende Anweisung gibt
    - M in eine endlose Folge von $\epsilon$-Transitionen gerät, ohne das Wort bis zu Ende zu lesen
- vorläufiges Ziel, ein äquivalenter DPDA M':
    - M' den Keller niemals leert
    - M' niemals blockiert
    - M' erlaubt keine endlosen Folgen von $\epsilon$-Transitionen
- Lösungen:
    - Füge neues Kellerinitialisierungssymbol ein, wird dieses gesehen, so blockiere
    - Wenn sich neuer DPDA M' in Zustand $z_{abl}$ befindet, so liest er Wort zu Ende und akzeptiert nicht
    - Wenn sich M' in Zustand $z_{akz}$ befindet, so liest er Wort zu Ende. Ist das restliche Wort $\epsilon$, so akzeptiert er, ist es nicht $\epsilon$, so wechselt er in $z_{abl}$ (und akzeptiert also nicht).

> Lemma: Sei M ein DPDA. Dann existiert ein DPDA $M_1$ mit $L(M)=L(M_1)$, so dass $M_1$ den Keller nie vollständig leert.

> Lemma: Zu jedem DPDA M existiert ein DPDA M' mit $L(M)=L(M')$, so dass M' jedes Wort w bis zum Ende liest

> Satz: Ist $L\subseteq \sum^*$ deterministisch kontextfrei, so auch $\sum^*\backslash L$

> Satz: aus einem DPDA M kann ein DPDA M' berechnet werden mit $L/M')=\sum^*\backslash L(M)$

## Abschlusseigenschaften
Erinnerung: Die Klasse der **regulären Sprachen** ist abgeschlossen unter
- Vereinigung ($L_1, L_2 \text{ regulär } \Rightarrow L_1\cup L_2 \text{ regulär }$)
- Schnitt ($L_1, L_2  \text{ regulär } \Rightarrow L_1\cap L_2 \text{ regulär }$)
- Komplement ($L \text{ regulär }\Rightarrow \sum^*\backslash L  \text{ regulär }$)
- Produkt/Konkatenation ($L_1, L_2 \text{ regulär }\Rightarrow L_1L_2 \text{ regulär }$ )
- Stern-Operation ($L \text{ regulär }\Rightarrow L^* \text{ regulär }$ )

Satz: die Klasse der **kontextfreien Sprachen** ist abgeschlossen unter
- Vereinigung ($L_1, L_2 \text{ kontextfrei } \Rightarrow L_1\cup L_2 \text{ kontextfrei }$)
- Produkt/Konkatenation ($L_1, L_2 \text{ kontextfrei }\Rightarrow L_1L_2 \text{ kontextfrei }$ )
- Stern-Operation ($L \text{ kontextfrei }\Rightarrow L^* \text{ kontextfrei }$ )
- 
die Klasse der kontextfreien Sprachen ist **nicht** abgeschlossen unter
- Schnitt ($L_1, L_2  \text{ kontextfrei } \Rightarrow L_1\cap L_2 \text{ kontextfrei }$)
- Komplement ($L \text{ kontextfrei }\Rightarrow \sum^*\backslash L  \text{ kontextfrei }$)
- 
es folgt
- Es gibt kontextfreie Sprachen, die nicht deterministisch kontextfrei sind.

## das Pumping Lemma für kontextfreie Sprachen
Idee: Man versucht auszunutzen, daß eine kontextfreie Sprache von einer Grammatik mit endlich vielen Nichtterminalen erzeugt werden muss. Das bedeutet auch: wenn ein Ableitungsbaum ausreichend tief ist, so gibt es einen Ast, der ein Nichtterminal mehrfach enthält. Die durch diese zwei Vorkommen bestimmten Teilbäume werden wir „pumpen“.

Pumping Lemma (Bar-Hillel, Perles, Shamir ’61):
```
Wenn L eine kontextfreie Sprache ist,
dann gibt es n>= 1 derart,
  daß für alle z in L mit |z| >= n gilt:
    es gibt Wörter u, v , w , x, y in SUM mit
      (i)   z = uvwxy ,
      (ii)  |vwx| <= n,
      (iii) |vx| >= 1 und
      (iv)  uv^i  wx^i y in L für alle i >= 0
```
Dieses Lemma spricht nicht über kontextfreie Grammatiken, sondern nur über die Eigenschaften der Sprache. Daher ist es dazu geeignet, Aussagen über Nicht-Kontextfreiheit zu machen.

- alle Sprachen, enthalten
  - Typ-0-Sprachen, enthalten
    - Typ-1-Sprachen (kontext sensitiv), enthalten
      - Typ-2-Sprachen (kontext frei), enthalten
        - Typ-3-Sprachen (rechtslinear)

Spielschema: Wir (die Beweiser) wollen zeigen, daß die Sprache L nicht kontextfrei ist. Dazu müssen wir das folgende Spiel (gegen den Gegner) gewinnen
1. G wählt eine Zahl $n\geq 1$
2. B wählt ein $z\in L$ mit $|z|\geq n$
3. G wählt u,v,w,x,y mit 
   1. $z=uvwxy$
   2. $|vwx|\leq n$
   3. $|vx|\geq 1$
4. B wählt ein i und zeigt, dass $uv^i wx^i y \not\in L$

Die Sprache L ist nicht kontextfrei, falls B unabhängig von den Wahlen von G in Runden 1 und 3 immer so wählen kann (in Runden 2 und 4), dass schließlich  $uv^i wx^i \not\in L$ gilt

Beispiel: $L=\{w2w| w\in\{0,1\}^*\}$ ist nicht kontextfrei

## das Lemma von Ogden (William Ogden)
Wenn L eine kontextfreie Sprache ist, dann gibt es $n\geq 1$ derart, dass für alle $z\in L$, in denen n Positionen markiert sind, gilt: es gibt Wörter $u,v,w,x,y\in\sum^*$ mit
1. $z=uvwxy$
2. v oder x enthält wenigstens eine der Markierungen oder
3. $uv^i wx^i y \in L$ für alle $i\geq 0$

