---
title: Computerbild
date: Wintersemester 20/21
author: Robert Jeutter
---

Computergrafik ist in erster Linie Bildsynthese mit dem Computer!

dabei zu lösende Teilaufgaben:
- identifiezierung relevanter mathematischer Funktionen
- Umsetzung passender/effizienter Algorithmen und Datenstrukturen
- Erzeugung virtueller Umgebungen
- Kompromisse zwischen Genauigkeit und Berechnungsaufwand

Aspekte der Computergrafik
- Mathematik
- Rasterkonvertierung
- Physik
- Physiologie
- Bildverarbeitung

# Grundlagen der Vektorgeometrie
## Grundlagen
### Vektorräume und Vektorrechnung
- ein Vektor $\vec{x}$ wird definiert als Element eines n-dimensionalen Zahlenraums
- ein Vektor wird als Zahlentupel (skalarer Wert) dargestellt, entweder als Zeilenvektor oder Spaltenvektor
- der Spaltenvektor wird auch $\vec{x}^t$ (Transponierte von x) genannt (und umgekehrt)
- Verallgemeinerung von Vektoren als Matrizen und Tensoren
- Tensoren dienen der Darstellung (Datenstruktur) von grafischen Objekten und Transformationen aber auch von Signalen, Farben und Bildern
- Vektoralgebra ist ein mächtiges Mittel zur Datenverarbeitung in der Vektorgeometrie

$\vec{x}=(x_1,x_2,...,x_n)$ oder $\vec{x}^T=\begin{pmatrix}x_1 \\ x_2 \\ ... \\ x_n \end{pmatrix}$

**Multiplikation**: Multiplikation eines Vektors mit einer skalaren Größe resultiert wiederum in einen Vektor

$\vec{q}=\alpha * \vec{x} = (\alpha *x_1, \alpha *x_2,...)$

**Addition**: Das Addieren zweier Vektoren im selben Vektorraum ergibt wieder einen Vektor

$\vec{x}+\vec{r}=(x_1+r_1, x_2+r_2,...)$

**Linearkombination**: Die Linearkomination mehrerer Vektoren ergibt einen Vektor

$\vec{o} = (\alpha * \vec{p})+(\beta *\vec{q})+(\gamma * \vec{r})$

**Lineare Unabhängigkeit**: eine Menge von Vektoren heißt linear unabhängig wenn keiner von ihnen als Linearkombination der anderen erzeugt werden kann.

**Länge** (Betrag) eines Vektors: $\vec{p}=(x,y,z): |\vec{p}|=\sqrt{x^2+y^2+z^2}$ Der Abstand zwischen zwei Punkten ist gleich der Länge des Differenzvektors

**Skalarprodukt**: $\vec{x}*\vec{r}=\sum_{i=0}^{n-1} x_i*r_i$ Das Skalarprodukt ist somit ein skalarer Zahlenwert. – Aus der Definition folgt u.a. die beiden Vektoren m ̈ussen dieselbe Anzahl Koordinaten haben.Senkrecht zu einander stehende Vektoren $\vec{x}$ und \vec{r} ergeben immer das Skalarprodukt Null.

**Winkel**: Ein Winkel $\phi$ zwischen den Vektoren $\vec{a}$ und $\vec{b}$ aus: $\vec{a}*\vec{b}=|\vec{a}|*|\vec{b}|*cos(\phi)$ mit $cos(\phi)=\frac{\vec{a}*\vec{b}}{|\vec{a}|*|\vec{b}|}$

Diese Winkelbestimmung ist im Bereich -180° bis +180° vorzeichenunabhängig, da $cos(\phi)=cos(-\phi)$. Es können also nur Winkel im Bereich $0 \geq \phi \geq \pi$

**Vektorprodukt** (Kreuzprodukt): Das Vektorprodukt $\vec{a}\times\vec{b}$ ist ein Vektor. 
$$\vec{a}\times\vec{b} = \begin{pmatrix} a_y b_z - a_z b_y \\ a_z b_x - a_x b_z \\ a_x b_y - a_y b_x \end{pmatrix}$$
Die Richtung des resultierenden Vektors ist senkrecht auf $\vec{a}$ und auf $\vec{b}$. Das Vorzeichen hängt von der Reihenfolge der Vektoren ab: $\vec{a}\times \vec{b}=-\vec{b}\times \vec{a}$. 
Entsprechend der Rechte-Hand-Regel ergibt eine Drehung von a nach b im Uhrzeigersinn ein negatives Vorzeichen und entgegen dem Uhrzeigersinn ein positives.

**Betrag des Kreuzprodukts**: Der Betrag des Vektors $(|\vec{a}\times\vec{b}|)$ ist gleich der Fläche des durch $\vec{a}$ und $\vec{b}$ aufgespannten Parallelogramms (Fläche = Basis * Höhe des Parallelogramms):
$$|\vec{a}\times\vec{b}|=|\vec{a}|*|\vec{b}|*sin(\phi) =|\vec{a}|·h$$
Der Winkel $\beta$ lässt sich also aus dem Kreuzprodukt ableiten. Aus dem Kreuzprodukt resultiert ein orientierungsabhängiges Vorzeichen. Es gilt: $sin(-\phi)=-sin(\phi)$

**Matrizen**: Matrizen sind Tupel von Vektoren aus demselben Vektorraum. Die Verallgemeinerung einer Matrix, nämlich ein Tupel von Matrizen wird auch Tensor genannt. Daher sind Matrizen und Vektoren spezielle Tensoren.

**Matrizenmultiplikation**: Jede Koordinate des resultierenden Vektors berechnet man als Skalarprodukt des entsprechenden Zeilenvektors der Matrix mit dem Vektor: $$r_i = A_i * \vec{x} = \sum_{k=1}^n a_{ik}*x_k$$
Vektoren werden als Spaltenvektor geschrieben und stehen bei der Multiplikation immer rechts der Matrix.
Bei einer entsprechenden Multiplikation für Zeilenvektoren würde die Matrix rechts stehen und wäre transponiert.

Die Koeffizienten der resultierenden Matrix $c_{ij}$ entsprechen dem Skalarprodukt der i-ten Zeile $A_i$ und der j-ten Spalte $B_j$ von A resp B.

Entsprechend der Definition für Skalarprodukte muss die Matrix A gleich viele Spalten haben wie Matrix B Zeilen. Es können folglich n x m-Matrizen mit m x o-Matrizen multipliziert werden, was in einer n x o-Matrix resultiert.

**Einheitsmatrix E**: Die Einheitsmatrix ist eine (quadratische) n x n-Matrix welche nur in der diagonalen Einsen als Koeffizienten und sonst überall Nullen enthält. Die Multiplikation einer Einheitsmatrix mit einem Vektor $\vec{x} lässt den Vektor unverändert, gleiches gilt für die Multiplikation mit einer Matrix ($E*\vec{x}=\vec{x}$).

**Inverse $A^{-1}$**: Die Inverse der Matrix A wird als $A^{-1}$ notiert. Sie ist definiert durch $A*A^{-1}=E$. Eine Inverse existiert nur für quadratische n x n-Matrizen welche aus n linear unabhängigen Vektoren zusammengesetzt ist.

**Transposition** von Matrizen: $(A*B)^T = B^T * A^T$

**Assoziativität**: Die Matrixmultiplikation ist immer assoziativ $A*(B*C)=(A*B)*C$

**Inversion**: $(A*B)^{-1} = B^{-1}*A^{-1}$

**Kommutativität**: ist im Allgemeinen bei Matrixmultiplikation nicht gewährleistet $A*B \not = B*A$

### Kartesiche Koordinaten
Dreidimensionales kartesisches Koordinatensystem werden aufgespannt durch die drei linear unabhängigen Einheitsvektoren $\vec{x}$,$\vec{y} und $\vec{z}.

3D-Punktobjekte werden durch Vektoren im $\R^3$ repräsentiert. Diese Vektoren werden Ortsvektoren genannt, da Sie einen Ort im Raum repräsentieren. Die Koordinaten eines Vektors sind wiederum eine senkrechte Projektion des Vektors auf die Koordinatenachse.

**Drehsinn**: Koordinatensysteme haben einen Drehsinn (positiv/negativ). Rechte-Hand-Regel: Daumen ist Rotationsachse, Fingerspitze zeigt positive Richtung.

### Elemente der Geometrie
Objekte werden als Linearkombination von Orts- und Richtungsvektoren zusammengesetzt. (Bsp Unendliche Gerade, Liniensegment,...)

Beachte: Orts und Richtungsvektoren haben die gleiche Darstellung im kartesischen Vektorraum, müssen aber unterschiedlich behandelt werden. Z.B. eine Translation einer Geraden darf sich nur auf den Orts- nicht auf den Richtungsvektor auswirken. Die Rotation muss auf beide Teile angewendet werden, etc.

**Ebenen**: Eine unbegrenzte Ebene p kann wiederum als Linearkombination aus Ortsvektor $\vec{q}$ und zwei linear unabhängigen Richtungsvektoren $\vec{r}$ und $\vec{s}$ definiert werden $p=\vec{q}+\alpha*\vec{r}+\beta * \vec{s}$

**Dreieck**: Punkte A,B und C $\vec{A}+\alpha*(B-A)+\beta*(C-A)$

## Transformationen 2D
Ziel der Transformation im Allgemeinen: Einheitliche Beschreibung der Transformation durch einheitliche Transformationsmatrizen
- alle auf iene Punktmenge anzuwendende Matrizen können dann vor der Anwendung auf die Punkte in einer Gesamtmatrix zusammengefasst werden
- auf jeden Punkt ist statt mehrerer Matrixoperationen nur noch eine anzuwenden
- effizientere Berechnung der Transformation

Arten:

**Translation**: Verschiebung eines mehrere Punkte P um den Vektor $\vec{t}$

**Skalierung**: Stauchung oder Streckung eines Objekts bezüglich des Koordinatenursprungs $P'=S*P$ (univorm vs nichtuniform).

**Spiegelung**: Spezialfall der Skalierung 
- an der x-Achse $S=\begin{pmatrix} 1 & 0 \\ 0 & -1 \end{pmatrix}$ (Vorzeichenumkehr für y-Koordinaten)
- an der y-Achse $S=\begin{pmatrix} -1 & 0 \\ 0 & 1 \end{pmatrix}$ (Vorzeichenumkehr für x-Koordinaten)
- am Ursprung $S=\begin{pmatrix} -1 & 0 \\ 0 & -1 \end{pmatrix}$ (entspricht Spiegelung an x-und y-Achse)

**Scherung**: Positionsabhängige Stauchung oder Streckung (Objekte ändern die Form, sind nicht starr) Punkte auf einer Geraden liegen aber auch nach der Scherung wieder auf einer Geraden (Eigenschaft von affinen Abbildungen):
$S=\begin{pmatrix} 1 & S_x \\ S_y & 1 \end{pmatrix}$

**Rotation mit Polarkoordinaten**: Die Rotation eines Punktes $P=(x,y)$ mit dem Drehwinkel $\theta$ um den Nullpunkt lässt sich einfacher über Polarkoordinaten $(r,\phi)$ herleiten. Der gedrehte Punkt wird dann $P'=(r,\phi+\theta)$

$r=\sqrt{x^2+y^2}$, $x=r* cos(\phi)$, $y=r* sin(\phi)$

$$\binom{x'}{y'}=\begin{pmatrix} cos(\theta) & -sin(\theta) \\ sin(\theta) & cos(\theta)\end{pmatrix}*\binom{x}{y}$$ 

Somit gilt $p'=R_\theta * P$

**Koordinatentransformation**: Ein Punkt P soll in ein gedrehtes (lokales) Koordinatensystem transformiert werden. Die lokalen Koordinaten erhält man durch Projektion des Punktes auf die lokalen Achsen (Skalarprodukte). Die lokalen Koordinatenachsen sind als Vektoren im Ursprungskoordinatensystem definiert. Sie stehen senkrecht aufeinander und haben die Länge 1. Die Koordinaten-Transformation kann als Matrixmultiplikation realisiert werden.
$$P' =T*P = \begin{pmatrix} x_x & x_y\\ y_x & y_y \end{pmatrix} * \binom{P_x}{P_y}$$

**Zusammenfassung**: Viele zweidimensionale Transformationen lassen sich als 2x2 Matrizen darstellen (ausnahme Translation). Um verschiedene Transformationen durch Operationen auszudrücken und Fallunterscheidungen vorzubeugen werden homogene Vektorräume verwendet.

## Homogene Vektorräume
Ein kartesischer Punkt $P_k$ mit dem Ortsvektor $(x',y')$ wird im homogenen Vektorraum durch eine zusätzliche Dimension w, als 3-Tupel $(x,y,w)$ dargestellt. Ein homogener Vektor $(x,y,w)$ entspricht dem kartesischen Vektor $(\frac{x}{w},\frac{y}{w})$.
Die homogene Komponente w kann dabei frei gewählt werden: Alle Punkte $P_H$ auf der unendlichen Geraden $(0,0,0)(x',y',1)$ entsprechen demselben kartesichen Vektor $(x',y')$ (Zentralprojektion auf kartesischer Ebene).

In vielen Anwendungsfällen wird bei Ortsvektoren im homogenen Vektorraum $w=1$ gewählt (1="Punkt", 0="Richtung"; kartesische Zahlenebene).

**Skalare Multiplikation** verändert das kartesische Äquivalent nicht: $\alpha * P_h = (\alpha*x, \alpha*y, \alpha*w)$ (Spezialfall 0 !)

**Translation**: Die Multiplikation mit einer Matrix A muss dasselbe Ergebnis liefern, wie eine Addition eines Translationsvektors $(\Delta x, \Delta y)$ zum kartesischen Punkt: $A*P=P+(\Delta x, \Delta y)$

Die Herleitung einer Matrix für A erfolgt durch folgendes Gleichungssystem für die Koeffizienten der Matrix:
$$\begin{pmatrix} a_{11} & a_{12} & a_{13}\\ a_{21} & a_{22} & a_{23}\\ a_{31} & a_{32} & a_{33} \end{pmatrix} * \begin{pmatrix}x \\ y \\ 1 \end{pmatrix} = \begin{pmatrix}x+\Delta x \\ y+\Delta y \\ 1\end{pmatrix}$$

**Skalierung, Projektion, Spiegelung** können durch folgende Matrix dargestellt werden: 
$$\begin{pmatrix} F_x & 0 & 0 \\ 0 & F_y & 0 \\ 0 & 0 & 1 \end{pmatrix} * \begin{pmatrix} x \\ y \\ 1 \end{pmatrix} = \begin{pmatrix} F_x*x \\ F_y*y \\ 1 \end{pmatrix}$$

Für eine Skalierung gilt $F_x,F_y>0$, für uniforme Skalierung gilt zusätzlich $F_X=F_y$. 

Mit $F_x=0$ oder $F_y=0$ kann eine Projektion auf die y-, bzw x-Achse ausgedrückt werden. Eine Projektion ist keine Skalierung im eigentlichen Sinne (und nicht invertierbar).

$F_x=-1$ oder $f_y=-1$ entspricht einer Spiegelung an der y- bzw x-Achse. Sind beide Faktoren $F_x=F_y=-1$, wird damit eine Spiegelung am Ursprung ausgedrückt. Eine Spiegelung ist invers zu sich selbst.



**Scherung** wird durch folgende Matrix repräsentiert:
$$\begin{pmatrix} 1 & a & 0 \\ 0 & 1 & 0 \\ 0 & 0 & 1 \end{pmatrix} * \begin{pmatrix} x \\ y \\ w \end{pmatrix} = \begin{pmatrix} x+a*y \\ y \\ w \end{pmatrix}$$

Sie bewirkt eine Translation der Punkte in x-Richtung, proportional zum Wert der y-Koordinate. Ein Rechteck wird dabei zu einem Parallelogramm verformt. Diese Transformation kann auch durch eine nicht uniforme Skalierung in einem gedrehten Raum realisiert werden (zusammen mit entsprechender Rotationsfunktion).



**Rotation**: Die Herleitung ist analog zur Rotation für kartesische Vektoren (die 2x2 Untermatrix ist identisch zum kartesischen Fall). Die w-Koordinate für Ortsvektoren bleibt durch Anwendung der Matrix unverändert.
$$R_\theta *P= \begin{pmatrix}cos(\theta) & -sin(\theta) & 0 \\ sin(\theta) & cos(\theta) & 0 \\ 0 & 0 & 1 \end{pmatrix} * \begin{pmatrix}x & y & 1 \end{pmatrix} = \begin{pmatrix} x cos(\theta) - y sind(\theta)\\ x sin(\theta)+y cos(\theta)\\ 1 \end{pmatrix}$$

Verknüpfung von Transformationen: Da sowohl die Rotation R als auch die Translation T sich als 3x3-Matrizen darstellen lassen, kann man die beiden Operationen durch Matrixmultiplikation in einer 3x3-Matrix verknüpfen. Man beachte, dass Matrixmultiplikationen zwar assoziativ, im Allgemeinen jedoch nicht kommutativ sind: $T*R*{Haus} = R*T*{Haus}$

### 2D Transformation mit Fixpunkten
Ein Objekt soll um einen Frei Wählbaren Pivotpunkt P gedreht werden. Für diese Transformation gibt es noch keine direkte Matrizenform. Daher wird die Operation aus bekannten Operationen zusammengesetzt
1. verschiebe von P in den Ursprung (Translation $T_{-P}$)
2. rotiere um Ursprung ($R_{90}$)
3. Translation zurück ($T_{+P}$)
In Matrixform sieht die Operation wie folgt aus: $T_{+P}*R_{90}*T_{+P}*{Objekt}$

Da die Matrixmultiplikation assoziativ ist, können zuerst die Matrizen multipliziert und dann auf das Polygon angewendet werden. Dies bewirkt dieselbe Transformation, ist viel eleganter und auch effizienter als einzelne Matrizen anzuwenden.


### Inverse Transformation
Eine inverse Translationsmatrix konstruiert man indem man bei der früher hergeleiteten Translationsmatrix den negativen Verschiebungsvektor einsetzt: $T_{\Delta x, \Delta y}^{-1} = T_{-\Delta x, -\Delta y}$

Korrektheit ergibt sich durch $T^{-1}*T=E$.

### Inverse Skalierung
definiert durch die Matrix:
$$S_{F_x, F_y}^{-1}=S_{\frac{1}{F_x},\frac{1}{F_y}}=\begin{pmatrix} \frac{1}{F_x} &0&0\\ 0&\frac{1}{F_y}&0\\ 0&0&1 \end{pmatrix}$$

### Inverse Rotation
ergibt sich als Drehung im Uhrzeigersinn 
$$R_{-\theta} = \begin{pmatrix} cos(\theta) & sin(\theta) & 0 \\ -sin(\theta) & cos(\theta) & 0 \\ 0 & 0 & 1 \end{pmatrix} = R_{\theta}^{T}$$

### Invertierung von verknüpften Transformationen
Die inverse Matrix der drei verknüpften Operationen A,B,C ergibt: $(A*B*C)^{-1}=C^{-1}*B^{-1}*A^{-1}$

D.h. die inverse Matrix ist die Verknüpfung der inversen Einzeloperation in umgekehrter Reihenfolge (Undo-Operation). DIe Korrektheit der Formel ergibt sich aus der folgenden Gleichung unter Anwendung des Assoziativgesetztes der Matrixmultiplikation $(ABC)^{-1}*ABC=E$

### Affine Abbildung
Affine Abbildungen sind Teilmengen der homogenen Abbildungen. Durch entsprechende Wahl von reellwertigen Koeffizienten können die bis hier eingeführten homogenen Transformationen der Ebene dargestellt werden.
$$\begin{pmatrix}a_1 & b_1 & c_1\\a_2 &b_2 & c_2\\ 0&0&1\end{pmatrix}*\begin{pmatrix} x_1\\y_1\\1\end{pmatrix}= \begin{pmatrix}x_1'\\y_1'\\1 \end{pmatrix}$$

- die letzte Zeile der affinen Matrix bleibt immer 0,0,1
- paralleles bleibt bei affinen Abbildungen stets parallel

Eine Zerlegung einer beliebigen affinen Transformation in die speziellen Transformationen (Rotation, Translation, Skalierung, Scherung) ist im Allgemeinen nicht eindeutig möglich. Die Summe der Parameter für Translation (2 Parameter) Rotation (1 Parameter), Skalierung (2 Parameter), Scherung (2 Parameter) beträgt 7 von denen allerdings nur 6 unabhängig sein können, da die Matrix 6 Koeffizienten besitzt. Daraus kann lässt sich schließen, dass einige Transformationen aus anderen Transformationen zusammengesetzt werden können. Z.B. Scherung aus Rotation und nicht uniformer Skalierung oder umgekehrt Rotation aus Scherungund nicht uniformer Skalierung.

**Affine Abbildung zwischen zwei Dreiecken** kann zwischen zwei beliebig gewählten Dreiecken in der Ebene definiert werden. 3 Punkte (6 Koordinaten) führen zu 6 Gleichungen zum Bestimmen der 6 Koeffizienten der affinen Abbildung (a,b,c,d,e,f).

### Transformation auf Orts- und Richtungsvektor
Richtungsvektoren können als Differenz zweier Ortsvektoren hergeleitet werden. Richtungsvektoren entsprechen kartesischen Punkten im Unendlichen. Sie werden auch uneigentliche Punkte genannt.

Eine Translations-Matrix wirkt sich nur auf Ortsvektoren aus. Richtungsvekoren bleiben bei Translation unverändert. Da bei der Berechnung nicht zwischen Orts- und Richtungsvektoren unterschiedenwerden lassen sich verknüpfte Transformationen effizient berechnen.

### Zusammenfassung bisher
- durch den "Kunstgriff" werden Transformationen vereinheitlicht und damit vereinfacht
- 2D kartesische Vektoren werden im 3D homogenen Vektorraum dargestellt
- wichtige Transformationen können einheitlich durch 3x3 Matrizen dargestellt werden
- Orts- und Richtungsvektoren werden unterschiedlich dargestellt aber mit der selben Transformationsmatrix automatisch korrekt und effizient transformiert.

## Homogene Transformation in 3D
Analog zum 2D Fall wird der Vektorraum um eine zusätzliche Dimension erweitert (Koordinate w).

3 Dimensionale kartesische koordinaten werden durch eine 4-dimensionale homogeen Vektorraum repräsentiert; er wird als 4-Tupel dargestellt. In vielen Anwendungsfällen wir w=1 gewählt (karteische Hyperebene).

Affine Abbildungen lassen die w-Koordinate unverändert

### Ebenen
- lassen sich grundsätzlich auch als Referenzpunkt und Richtung speichern
- für Berechnungen ist folgende Repräsentation sinnvoll: (a,b,c,d) wobei (a,b,c)=(nx,ny,nz) und d der Abstand der Ebene zum Ursprung. Dann ist für einen in der Ebene enthaltenen Punkt das Skalarprodukt aus Ebene und Punkt gleich 0

1. Ebene definiert durch 3 Punkte
   $$\begin{pmatrix}
    x_1 & x_2 & x_3 & 0\\
    y_1 & y_2 & y_3 & 0\\ 
    z_1 & z_2 & z_3 & 0\\
    1 & 1 & 1 & 1
    \end{pmatrix}$$
2. Translation um Vektor $(\Delta x, \Delta y,\Delta z)$
   $$\begin{pmatrix}
    1 & 0 & 0 & \Delta x\\
    0 & 1 & 0 & \Delta y\\ 
    0 & 0 & 1 & \Delta z\\
    0 & 0 & 0 & 1
    \end{pmatrix}$$
3. Skalierung um Faktor $F_x,F_y,F_z$
   $$\begin{pmatrix}
    F_y & 0 & 0 & 0\\
    0 & F_y & 0 & 0\\ 
    0 & 0 & F_z & 0\\
    0 & 0 & 0 & 1
    \end{pmatrix}$$
4. Rotation um z-Achse
   $$\begin{pmatrix}
    cos(\theta) & -sin(\theta) & 0 & 0\\
    sin(\theta) & \cos(\theta) & 0 & 0\\ 
    0 & 0 & 1 & 0\\
    0 & 0 & 0 & 1
    \end{pmatrix}$$
5. Rotation um die x-Achse
   $$\begin{pmatrix}
    1 & 0 & 0 & 0\\
    0 & cos(\theta) & -sin(\theta) & 0\\ 
    0 & sin(\theta) & cos(\theta) & 0\\
    0 & 0 & 0 & 1
    \end{pmatrix}$$
6. Rotation um die y-Achse
   $$\begin{pmatrix}
    cos(\theta) & 0 & sin(\theta) & 0\\
    0 & 1 & 0 & 0\\ 
    -sin(\theta) & 0 & cos(\theta) & 0\\
    0 & 0 & 0 & 1
    \end{pmatrix}$$

### Kommutativität
allgemein sind Transformationen nicht kommutativ; außnahme bilden zwei Rotationen um die selbe Achse

### Kameratransformation
Kamera ist definiert durch
- Lage des Augpunktes E (in Weltkoordinaten)
- Blickrichtung D
- Oben-Vektor U ("view up vector", senkrecht zu D)

