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
Ist $\Sum$ Alphabet, so nennen wir die Elemente oft Buchstaben.
Ist $\Sum$ ein Alphabet, so heißen die Elemente von $\Sum*$ auch Wörter über $\Sum$ (auch String/Zeichenkette)

Beispiele:
- Alphabete:{0},{0,1,2},...{A,K,S,0,1,2,3,4,5,6,7,8,9}, {groß,klein}
- keine Alphabete: $\emptyset, \N, \Q$
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
- es gibt ein auslöschendes Element $\emptyset$

> Definition: Sei L Sprache und $n\in\N$. Dann ist $L^n$ induktiv definiert:
$L^n = {\epsilon} \text{ falls } n=0; LL^{n-1} \text{ falls } n>0$

> Definition: Sei L eine Sprache. Dann ist $L*=\bigcup_{n\geq 0} L^n$ der Kleene-Abschluss oder die Kleene-Iteration von L. Weiter ist $L+ = \bigcup_{n\geq 0} L^n$

$L+ = L* L* = L* * L$

Beobachtung: Sei $\Sum$ Alphabet.
- Sind $L_1$ und $L_2$ Sprachen über $\Sum$, so auch die Verkettung $L_1L_2$, die Kleene-Iteration $L_1*$, die positive Iteration $L_1+$, die Vereinigung $L_1\cup L_2$, die Differenz $L_1 \ L_2$ und der Schnitt $L_1 \cap L_2$.
- $\emptyset, \Sum, \Sum*$ sind Sprachen über $\Sum$

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


# Rechtslineare Sprachen
werden durch Typ 3 erzeugt

## endliche Automaten (Maschinen)
anderer blickwinkel für rechtslineare Sprachen (ohne Speichereinheit)
Eingabe: Folge von " Buchstaben"

> Definition: ein deterministischer endlicher Automat M ist ein 5-Tupel $M=(Z, \sum, z_0, \delta, E)$
- $Z$ eine endliche Menge von Zuständen
- $\sum$ das Eingabealphabet (mit $Z\cap\sum = \emptyset$)
- $z_0\inZ$ der Start/Anfangszustand
- $\delta: Z \times \sum \rightarrow Z$ die Überführungs/Übergangsfunktion
- $E\subseteq Z$ die Menge der Endzustände

Abkürzung: DFA (deterministic finite automaton)

Bsp:
- $Z={0,1}$
- $\sum={a,b$}
- $z_0=0$
- $\delta(0,a)=\delta(1,b)=1, \delta(1,a)=\delta(0,b)=0$
- $E={0}$
- 
in DFA darf es nur einen einzigen Startzustand geben!
im Graphendiagramm: jeder Knoten hat die anzahl der alphabete als kanten

die (einmal lesende) $\delta$ Funktion wird verallgemeinert: $\hat{\delta}$, die die Übergänge für ganze Wörter ermittelt

> Definition: Zu einem gegebenen DFA definieren wir die Funktion $\hat{\delta}: Z \times \sum^* \rightarrow Z$ induktiv wie folgt, wobei $z\in Z$, $w\in\sum^+$ und $a\in \sum$:
- $\hat{\delta}(z, \epsilon) = z$
- $\hat{\delta}(z,aw)= $\hat{\delta}(\delta(z,a),w)$

Der Zustand $\rrof{\delta)$ ergibt sich indem man vom Zustand z aus dem Pfad folgt der mit w beschriftet ist.

> Definition: die von einem DFA **akzeptierte Sprache** ist: $L(M)={w\in\sum^* | \hat{\delta}(z_0,w)\in E}$

d.h. wenn der Pfad der im Anfangszuststand beginnt nach den Übergangen durch w-markierte Pfade in einem Endzustand endet

> Definition: EIne Sprache $L \supseteq \sum^*$ ist regulär, wenn es einen DFA #####################################
(wird von einem DFA akzeptiert)


> Proposition: Jede reguläre Sprache ist rechtslinear
Beweis: sei M ein DFA, definiere eine Typ-3 Grammatik G wie folgt:
- $V=Z$
- $S=z_0$
- $P={z\rightarrow a \delta(z,a) | z\in Z, a\in \sum} \cup {z\rightarrow \epsilon | z\in E}$ (Regeln abgeleitet aus Graphen mit Kanten; letzte Regel um ENdzustand in ein Terminal zu wandeln).

Behauptung: für alle $z,z'\inZ$ und $w\in \sum^*$ gilt: $z\Rightarrow^*_G wz' \Leftrightarrow \hat{\delta} (z,w)=z'$. Beweis durch Induktion über $|w|$.
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

$w\in L(M') \leftrightarrow \roof\gamma (S,w)\in F \leftrightarrow \roof\delta(S,w)ßcap E\not = \emptyset \leftrightarrow w\in L(M)$ und damit $l(M')=L(M)$

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
\delta(z,a) &\text{ falls } \delta(z,a)\cap E = \varemtpy \\
\delta(z,a)\cup S &\text{ sonst } \end{cases}$


> Satz: Wenn L eine reguläre Sprache ist, dann ist auch $L^*$ regulär.

Beweis: Nach dem Lemma zuvor ist $L^+$ regulär. Da auch ${\epsilon}$ regulär ist folgt mit ${\epsilon}\cup L^+ = L^0 \cup \bigcup L^n = L^*$

## Reguläre Ausdrücke
reguläre Ausdrücke erlauben es, die regulären Sprachen kompakt in "Textform" zu beschreiben

> Definition: Die Menge $Reg(\sum)$ der **regulären Ausdrücke über dem Alphabet $\sum$** ist die kleinste Menge mit folgenden Eigenschaften:
> - $\varempty \in Reg(\sum), \lambda \in Reg(\sum), \sum \subseteq Reg(\sum)$
> - Wenn $\alpha, \betaa \in Reg(\sum)$, dann auch $(\alpha * \beta), (\alpha + \beta), (\alpha^*)\in Reg(\sum)$

- für $\alpha * \beta$ schreibt man oft $\alpha\beta$
- für $\alpha + \beta$ schreibt man auch $\alpha|\beta$

Beispiel: $\sum={a,b,c,d}: \lambda ((ab)b) ((a+d)a) ((((ab)a)) + ((ba)b*))$

> Definition: Für einen regulären Ausdruck $\alpha \in Reg(\sum)$ ist die Sprache $L(\alpha)\subseteq \sum^*$ induktiv definiert
$$L(\alpha)=\begin{cases}
\varemtpy &\text{ falls } alpha=\not O \\
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
- $^x$ bindet stärker als $*$
- $*$ bindet stärker als $+$

Wo tauchen reguläre Ausdrücke auf:
- Suchen und Ersetzten
- Pattern Matching
- Übersetzung (von Programmiersprachen)

> Proposition: zu jedem regulären Ausdruck $\gamma$ gibt es einen NFA M mit $L(\gamma)=L(M)$

Beweis: per Induktion über den Aufbau von $\gamma$

> Proposition: zu jedem DFA M gibt es einen regulären Ausdruck $\gamma$ mit $L(M)=L(\gamma)$

Beweis: Sei M ein DFA. Konstruiere einen regulären Ausdruck mit $\gamma$ mit $L(M)=L(\gamma)$. Für ein Wort $w\in \sum^*$ sei $Pref(w)={u\in\sum^* | \exists v:w = uv, \epsilon\not= u\not= w}$ die Menge aller nicht-leeren echten Präfixe von w.

Sei $L\subseteq \sum^*$ eine Sprache, dann sind äquivalent
- L ist regulär, d.h. es gibt einen DFA M mit $L(M)=L$
- es gibt einen NFA M mit $L(M)=L$
- L ist rechtslinear, d.h. es gibt eine rechtslineare Grammatik G mit $L(G)=L$
- Es igbt einen regulären Ausdruck $\gamma$ mit $L(\gamma)=L$

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

> Lemma: Für jedes Alphabet $\sum$ ist die Menge ${L(G) | \text{G Grammatik über} \sum}$ abzählbar unendlich.

$|P(\sum^*)\cap RE|=|RE|=|\N|$

> Satz: Für jedes Alphabet $\sum$ ist die Menge $P(\sum^*)={L|L \text{Sprache über} \sum}$ überabzählbar, d.h. es gibt keine bijektive Funktion $F:\N \rightarrow P(\sum^*)$.

Beweis: Indirekt "Diagonalisierung"

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

Dieses Lemma spricht nicht über Automaten, sondern nur über die Eigenschaften der Sprache.

### Myhill-Nerode Äquivalenz
[...]

Der Index $index(R)$ von R ist die Anzahl der Äquivalenzklassen von R.

> Satz von Myhill-Nerode: Sei L eine Sprache. L ist regulär $\leftrightarrow index(R_L)< \infty$
(d.h. nur wenn die Myhill-Nerode-Äquivalenz endliche Klassen hat)

Beweis:
- "$Rightarrow$": Sei L regulär -> es gibt DFA M mit $L(M)=L$;
- "$Leftarrow$": sei $index(R_L)< \infty$;

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

> Definition: Sei M ein DFA. Dann ist $M'=(Z\/_{\equiv},\sum, [z_0],\sigma', E')$ mit
> - $\sigma'([z],a)=[\sigma (z,a)]$ für $z\in Z$ und $a\in \sum$ und
> - $E'=\{[z]|z\in E\}
> der Quotient von M bzgl $\equiv$
(es wird nicht mehr jeder einzelne Fall betrachtet sondern "ganze Gruppen"; Bsp Sitz->Reihe)

> Lemma: Ist M ein DFA und M' sein Quotient bzgl. $\equiv$, so ist M' ein DFA mit $L(M)=L(M')$

Es bleibt zu zeigen, dass $\sigma'$ wohldefiniert ist $\rightarrow z\equiv z' \rightarrow \sigma (z,a)\equiv \sigma (z',a) \rightarrow [\sigma (z,a)]=[\sigma (z',a)]$. Also ist M' tatsächlich ein DFA.

> Definition: Seien $M_i$ DFAs und $f:Z_1 \rightarrow Z_2$ eine Funktion. Dann ist f ein Homomorphismus von $M_1$ auf $M_2$, falls gilt:
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

