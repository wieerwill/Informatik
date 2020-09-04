---
title: Grundlagen und diskrete Strukturen
---
# Aussagen
Aussagen sind Sätze die wahr oder falsch sind, d.h. der Wahrheitswert ist wahr oder falsch.
> "5 ist prim" -> Aussage, wahr \
> "dieser Satz ist falsch" -> keine Aussage

Für keine natürliche Zahl n>3 ist die Gleichung x^n+y^n=z^n in positiven ganzen Zahl lösbar ~ Fermatsche Ex-Vermutung

## Verknüpfungen von Aussagen
Seien p und q Aussagen, dass sind folgende Sätze auch Aussagen
- $p \wedge q$ "und"
- $p \vee q$ "oder"
- $\neg p$ "nicht"
- $p \rightarrow q$ "impliziert"
- $p \leftrightarrow q$ "genau dann wenn"

Der Wahrheitswert dieser Verknüpfung ergibt sich aus den Wahrheitswerten p,q wie folgt
| p | q | $p\wedge q$ | $p\vee q$ | $\neg q$ | $p\rightarrow q$ | $p\leftrightarrow q$ |
| -- | -- | -- | -- | -- | -- | -- |
| f | f | f | f | w | w | w |
| f | w | f | w | w | w | f |
| w | f | f | w | f | f | f |
| w | w | w | w | f | w | w |

Aussagenlogische Variablen: Variable die den Wert w oder f annimmt

Aussagenlogische Formel: Verknüpfung aussagenloser Variablen nach obrigen Muster

Belegung: Zuordnung von w/f an jede Variable einer aussagenlogischer Formel

Wahrheitswerteverlauf: Wahrheitswert der Aussagenformel in Abhängigkeit von der Belegung der Variable

Tautologie: Formel deren Wahrheitswerteverlauf konstant w ist

Kontradiktion: Formel deren Wahrheitswerteverlauf konstant f ist

Kontraposition: $(p\rightarrow q)\leftrightarrow (\neg q \rightarrow p)$ ist eine Tautologie
Modus Potens: $(p\vee (p\rightarrow q))\rightarrow q$ ist eine Tautologie

Äquivalenz: Zwei Formeln p,q sind äquivalent (bzw logisch äquivalent) wenn $p\leftrightarrow$ Tautologie ist. Man schreibt $p \equiv q$

Die Formel p impliziert die Formel q, wenn $p\rightarrow q$ eine Tautologie ist

## Regeln
- $p\wedge q \equiv q \wedge p$ (Kommutativ)
- $p\vee q \equiv q \vee p$ (Kommutativ)
- $p\wedge (q \wedge r) \equiv (p \wedge q) \wedge r$ (Assoziativ)
- $p\vee ( q \vee r) \equiv (p \vee q) \vee$ (Assoziativ)
- $p\wedge (q\vee r) \equiv (p\wedge q) \vee (p\wedge r)$ (Distributiv)
- $p\vee (q\wedge r) \equiv (p\vee q) \wedge (p\vee r)$ (Distributiv)
- $\neg(\neg q) \equiv q$ (Doppelte Verneinung)
- $\neg(p\wedge q) \equiv (\neg p) \wedge (\neg q)$ (de Morgansche)

Aussagenform über den Universen $U_1,...,U_n$: Satz mit Variablen $x_1,...,x_n$ der bei Ersetzung jedes x durch ein Objekt am $U_j$ stets zu einer Aussage wird.
Variablen können mehrfach auftreten, werden aber jeweils durch das gleiche Objekt (aus $U_j$) ersetzt.
- "x ist prim" ist eine Aussagenform über dem Universum $\N$ der natürlichen Zahlen
- "$x<y$" ist eine Aussagenform über dem Universum $\R$ der reellen Zahlen
- "x ist wahr" ist eine Aussagenform über dem Universum der Aussagen
- "x ist falsch" ist keine Aussagenform über dem Universum aller Sätze

Aussagenformen in einer Variable x aus dem Universum U heißen Prädikate von U. 
Aussagenformen in n Variablen $x_1,...,x_n$ aus dem Universum U heißen "n-stellige Prädikate" von U.
Nach Ersetzung von x im 2-stelligen Prädikat "$x<y$" etwa durch "17" entsteht das 1-stellige Prädikat "$17<y$".

Sei p(x) ein Prädikat über dem Universum U (z.B. p(x) ist "x ist prim")
- "$\forall x:p(x)$": ist die Aussage "für alle x aus U ist p(x) wahr"
- "$\exists x:p(x)$": ist die Aussage "es gibt ein x aus U für das p(x) wahr ist"

Leeres Universum U (U enthält keine Objekte)
- "$\forall x:p(x)$": ist wahr (für jedes Prädikat)
- "$\exists x:p(x)$": ist falsch (für jedes Prädikat)

Endliches Universum U, etwa aus Objekte $a_1,...,a_n$
- "$\forall x:p(x)$": bedeutet $p(a_1)\wedge p(a_2) \wedge ... \wedge p(a_n)$ ist wahr/falsch
- "$\exists x:p(x)$": bedeutet $p(a_1)\vee p(a_2) \vee .. \vee p(a_n)$ ist wahr/falsch

Regeln: Seien p,q Prädikate über U
- $(\forall x: (p(x) \wedge q(x)))\leftrightarrow (\forall x: p(x) \wedge \forall x: q(x))$
- $\exists x: (p(x) \vee q(x)) \leftrightarrow (\exists x: p(x) \vee \exists x: q(x))$
- $\neg (\forall x:p(x))\leftrightarrow \exists x: \neg p(x)$
- $\neg(\exists x:p(x))\leftrightarrow \forall x:\neg p(x)$
Schachtelung von Quantoren ($\forall, \exists)$. Sei $p(x,y)$ 2-stelliges Prädikat über$U_1, U_2$: $\forall x: \exists y:p(x,y)$. Achtung: Verschiedenartige Quantoren dürfen nicht getauscht werden! gleichartige Quantoren dürfen getauscht werden

Negation: $\neg (\forall x \forall y \exists z \forall w \exists v: p(x,y,z)\rightarrow q(w,v)$
$\exists x \exists y \forall z \exists w \forall v: \neg (p(x,y,z)\rightarrow q(w,v))$

# Mengen
> Eine Menge ist eine Zusammenfassung bestimmter, wohlunterschiedener Objekte unserer Anschauung oder unseres Denkens. (Cantor)
Von jedem Objekt steht fest, ob es zur Menge gehört oder nicht.

Bsp: ${M,A,T,H,E,M,A,T,I,K} \approx {M,A,T,H,E,I,K}:$ Mengen der Buchstaben des Wortes Mathematik

## Probleme der naiven Mathematik
### Wunsch 1
"$x\in y$" soll Aussagenform über dem Universum U aller Mengen sein. D.h. für je zwei Mengen x und y ist entweder x ein Element von y oder nciht. D.h. "$x\in y$" ist ein 2-stelliges Prädikat über U.
### Wunsch 2
Ist p(x) ein Prädikat über U, so soll es eine Menge geben, die aus genau denjenigen Mengen x besteht, für die p(x) wahr ist. Bezeichnung ${x:p(x)$ ist wahr $}$.
Danach gäbe es eine Menge M, die aus genau denjenigen Mengen x mit $x\not \in x$ besteht: $M={x:x\not \in x}$.
D.h. Wunsch 1 und 2 führen zu einem Widerspruch in der Mengenlehre!\
Lösung: Aussonderung nur an bereits "gesicherten" Mengen\
#### Wunsch 2':
Ist A eine Menge und p(x) ein Prädikat über U, dann gilt es eine Menge B die aus genau denjenigen Mengen x aus A besteht, für die p(x) wahr ist. Bezeichnung: $B={x\in A:p(x) wahr}$.
Folgerung: die Gesamtheit aller Mengen ist selbst keine Menge, sonst findet man einen Widerspruch wie oben.

### Wunsch 3
Zwei Mengen x,y sind genau dann gleich wenn sie diesselben Elemente enthalten. D.h. $x=y: \leftrightarrow \forall z:(z\in x \leftrightarrow z\in y)$. Somit gilt für zwei Prädikate p(x), q(x) über U und jede Menge A: ${x\in A: p(x) wahr} = {x\in A: q(x) wahr}$ genau dann, wen q(x), p(x) den gleichen Wahrheitswert für jedes x aus A haben.

### Wunsch 0
Es gibt eine Menge. Ist A irgendeine Menge, so ist ${x \in A: \neg (x=x)}$ eine Menge ohne Elemente, die sogenannte leere Menge $\varemtpy$.

### Wunsch 4
Zu jeder Menge A gibt es eine Menge B, die aus genau denjenigen Mengen besteht, die Teilmengen von A sind. Dabei ist x eine Teilmenge von $y: \leftrightarrow \forall z:(z\in x \rightarrow z \in y) [x \subseteq y]$\
$B={x:x\subseteq A}=\wp(A)$ B heißt Potentmenge von A\
Bsp: $\wp({1,2,3}) = {\varempty, {1},{2},{3},{1,2},{1,3},{2,3},{1,2,3})$ (Daraus lässt sich ein Hesse-Diagramm zeichnen).

## Teilmengen
A Teilmenge von B $\leftrightarrow \forall x: (x\in A \rightarrow x \in B):\Rightarrow A\subseteq B$\
A Obermenge von B $\leftrightarrow \forall x: (x\in B \rightarrow x \in A):\Rightarrow A\supseteq B$\
Folglich $A=B \leftrightarrow A\subseteq B \wedge B\subseteq A$\
Schnittmenge von A und B: $A\cap B = {x: x\in A \wedge x\in B}$\
Vereinigungsmenge von A und B: $A\cup B = {x: x\in A \vee x\in B}$

Sei eine Menge (von Mengen) dann gibt es eine Menge die aus genau den Mengen besteht, die in jeder Menge von A enthalten sind (außer $A=\varemtpy$).
Ebenso gibt es Mengen die aus genau den Mengen besteht, die in wenigstens einer Menge aus A liegen. Die Existenz dieser Menge wird axiomatisch gefordert in ZFC:$ UA = {x: \exists z \in A: x \in z}$\

Seien A,B Mengen, dann sei $A/B:={x\in A: x\not \in B } = A\bigtriangleup B$\
De Moorgansche Regel: $\overline{A \cup B} = \overline{A} \cap \overline{B}$ und $\overline{A\cap B}=\overline{A}\cup \overline{B}$\
Das geordnete Paar (x,y) von Mengen x,y ist definiert durch ${{x},{x,y}}:={x,y}$\
A und B Mengen: $A x B:={(x,y):x\in A \wedge y \in B}$

# Relationen
$A={Peter, Paul, Marry}$ und $B={C++, Basic, Lisp}: $R\subseteq AxB$, etwa {(Peter,c++),(Paul, C++), (Marry,Lisp)}. Seien A,B Mengen: Eine Relation von A nach B ist eine Teilmenge R von AxB.\
$(x,y)\in R:$ x steht in einer Relation R zu y; auch xRy\
Ist A=B, so heißt R auch binäre Relation auf A

## binäre Relation
1. Allrelation $R:=AxA \subseteq AxA$
2. Nullrelation $R:=\varemtpy \subseteq AxA$
3. Gleichheitsrelation $R:={(x,y)... x=y}
4. $A=R$ $R:={(x,y)\in \R x \R, x \leq y}$
5. $A=\Z$ $R:={(x,y)\in \Z x \Z:$ x ist Teiler von y $}$ kurz: x|y

## Eigenschaften von Relationen
Sei $R\in AxA$ binäre Relation auf A
1. Reflexiv $\leftrightarrow$ xRx $\forall x \in A$
2. Symetrisch $\leftrightarrow xRy \rightarrow yRx$
3. Antisymetrisch $\leftrightarrow xRy \wedge yRx \rightarrow x=y$
4. Transitiv $\leftrightarrow xRy \wedge yRz \rightarrow xRz$
5. totale Relation $\leftrightarrow xRy \vee yRx  \forall x,y \in A$

- R heißt Äquivalenzrelation $\leftrightarrow$ R reflexiv, symetrisch und transitiv
- R heißt Ordnung $\leftrightarrow$ R reflexiv, antisymetrisch und transitiv
- R heißt Totalordnung \$leftrightarrow$ R Ordnung und total
- R heißt Quasiordnung $\leftrightarrow$ R reflexiv und transitiv