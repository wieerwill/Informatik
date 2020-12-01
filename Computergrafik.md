---
title: Computergrafik
date: Wintersemester 20/21
author: Robert Jeutter
---

Computergrafik ist in erster Linie Bildsynthese mit dem Computer!

dabei zu lösende Teilaufgaben:
- identifizierung relevanter mathematischer Funktionen
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

### Kartesische Koordinaten
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

## Projektion
3D Objekt auf eine Ebene projiezieren:
- Teil der Kameratransformation
- erfolgt meist in Kamerakoordinaten
- Projektionsarten
  - Parallelprojektion (z.B. Ansicht von oben) stets affine Projektion
  - zentralperspektivische Projektion (Zentralperspektive) keine affine Projektion, d.h. im Allgemeinen bleibt paralleles nicht parallel

### Orthogonale Projektion
- einfachste der Parallelprojektionen
- Projektionsebene ist parallel zur XY Ebene
- Projektionsrichtung hier stets parallel zur z-Achse (rechtwinklig zur Projektionsebene)
- z Koordinaten werden auf gleichen Wert gesetzt (z.B. 0 ist dann die Projektionsmatrix)
- Anwendung: $O'=P*R*T*O$ wenn T und R die Transformationsschritte der Kameraprojektion sind und O das Objekt in Weltkoordinaten
$$P=\begin{pmatrix}
    1&0&0&0\\
    0&1&0&0\\
    0&0&0&0\\
    0&0&0&1
    \end{pmatrix}$$

### Schiefwinklige Parallelprojektion
- typische Parallelprojektion mit 2 Parametern
- Projektionsebene ist parallel zur XY Ebene
- Projektionsrichtung hat zwei Freiheitsgrade und ist typischerweise nicht orthogonal zur Projektionsebene (d.h. schiefwinklig)
- Projektionsrichtung (Schiefe) ist über 2 Winkel parametrisierbar
- Herleitung
    $P=\begin{pmatrix}
        1 & 0 & -cos(\alpha)*f & 0 \\
        0 & 1 & -sin(\alpha)*f & 0 \\
        0 & 0 & 0 & 0 \\
        0 & 0 & 0 & 1 
      \end{pmatrix}$$
- es gilt: $x'=x-cos(\alpha)*f*z$ und $y'=y-sin(\alpha)*f*z$


### Zentralperspektive
- entspricht einer Lochkamera bzw etwa dem "einäugigen" Sehen
- Augpunkt im Ursprung des Kamerakoordinatensystems
- Projektionsfläche ist eine Ebene parallel zu XY Ebene
- Eigenschaften
  - perspektivische Verkürzung
  - parallele Linien des Objekts fluchten oft in einen Fluchtpunkt

$$\begin{pmatrix} d&0&0&0\\ 0&d&0&0 \\ 0&0&0&1 \\ 0&0&1&0 \end{pmatrix} * \begin{pmatrix}x\\y\\z\\1\end{pmatrix} = \begin{pmatrix} d*x\\ d*y\\ 1 \\ z \end{pmatrix} \rightarrow \begin{pmatrix} \frac{d*x}{z} \\ \frac{d*y}{z} \\ \frac{1}{z} \end{pmatrix}$$

Fluchtpunkte
- hat ein Modell parallele Kanten oder parallele Striche in Texturen, dann ergibt sich für jede solche Richtung r in der Abbildung ein Fluchtpunkt, auf den diese parallelen Kanten/Striche hinzu zu laufen scheinen
- es gibt jedoch Ausnahmen, bei denen Paralleles in der Abbildung Parallel bleibt (z.B. horizontale Kanten der Schwellen in der Abbildung)
- Da es beliebig viele Richtungen geben kann, sind auch beliebig viele Fluchtpunkte in einem Bild möglich
- Rotationen können Fluchtpunkte ändern, Translationen jedoch nicht

Ermittlung eines Fluchtpunktes: Wird aus einer Richtung r und dem Aufpunkt eine Gerade definiert, dann schneidet diese Gerade die Projektionsfläche im Fliuchtpunkt für die Richtung r.

- Eine Richtung r, die in der Projektionsfläche enthalten ist, führt zu einer Gerade durch den Augpunkt, welche nie die Projektionsfläche schneidet. Alle Linien mit einer solchen Richtung bleiben folglich parallel
- Der Fluchtpunkt der Richtung r ist abhängig von 1. dieser Richtung, 2. der Projektionsfläche und 3. dem Augpunkt
- Nur wenn eines der 3 obigen Elemente geändert wird, ändert sich die Lage des Fluchtpunktes von r
- da Verschiebungen von Objekten weder deren Richtungen, den Augpunkt oder die Projektionsebene verändern, belibt die Lage der Fluchtpunkte bei Verschiebungen stets erhalten
- Die Rotation eines Objektes ändert im Allgemeinen die im Objekt enthaltenen Richtungen und damit auch deren Fluchtpunkt


### Zusammenfassung
- Mittels Matrixmultiplikation kann eine Folge unterschiedlicher 3D-Transformationen in einer einzigen 4x4-Matrix zusammengefasst werden. Dies schließt Projektionsmatrizen (Abbildung von 3D nach 2D) mit ein.
- Affine Abbildungen lassen die w-Koordinate unverändert. Bei Parallelprojektionen ist das so.
- Die perspektivische Kameratransformation ist eine allgemeine homogene Matrix und keine affine Abbildung. Die w-Koordinate kann dadurch verändert werden. Zur Rückführung in kartesische Koordinaten ist eine Division durch die w-Koordinate erforderlich!
- Bei zentralperspektivischer Projektion ergibt sich pro Schar paralleler Kanten/Texturlinien/etc jeweils ein Fluchtpunkt (Spezialfall: Richtung ist parallel zur Projektionsebene, dann Fluchtpunkt im Unendlichen). Durch Rotation eines Objektes (relativ zur Kamera) ändert sich im Allgemeinen die Lage der Fluchtpunkte. Neben dem gestalterischen Aspekt (Bildkomposition) spielen Fluchtpunkte bei der Bilderkennung (z.B. Berechnung der Ausrichtung von 3D-Objekten) eine Rolle


# Modellierung
## Geometrische Modellierung
### Grundlagen
Bei der geometrischen Modellierung geht es im allgemeinen um die computergestütze Beschreibung der Form geometrischer Objekte

Objekte:
- Beschreibung von dreidimensionalen geometrischen Formen
- verschiedenste Formate existieren, meistens eine Gruppierung der geometrischen Eigenschaften (Eckpunkte, Kanten, Flächen)

Dateiformate:
- für das speichern der dreidimensionalen geometrischen Formen gibt es verschiedenste Dateiformate
- STL: ist beispielweise Standard für viele CAD Systeme
- OBJ: weitverbreitetes Dateiformat


### B-Rep
B-Rep = Boundary Representation: Für die Beschreibung dreidimensionaler Festkörper gibt es mehrere Möglichkeiten. Ein Standard ist die Boundary Representation, eine Modellgeschreibung durch die festlegung begrenzender Oberflächen
- Darstellungsform eines Flächen- oder Volumenmodells
- beschreibt Objekt durch begrenzende Oberflächen
- sind schnell verarbeitbar
- Definition eines Ojekts erfolgt über einen vef-Graph (vertex, edge, face)
  - Knotenliste: beinhaltet Koordinatenpunkt
  - Kantenliste: für jede Kante werden zwei Punkte referenziert
  - Flächenliste: für jede Fläche wird Reihenfolge von Kanten angegeben


## Szenengraph
Szene (Computergrafik)
- eine dreidimensionale Beschreibung von Objekten, Lichtquellen und Materialeigenschaften
- setzt virtuellen Betrachter voraus, sowie dessen Position und Blickwinkel

Szenegraph:
- hierarchische Gruppierung der Objekte in einer Szene
- somit eine objektorientierte Datenstruktur
- aus graphentheoretischer Sich: gerichteter Graph ohne Kreise


## Rendering
Beim rendern erfolgt eine Bilderzeugung aus einer gegebenen Szene. Der Weg von der Szene bis zum fertigen Bild erfolgt dabei über eine sogenannte **Render-Pipeline**:

Geometrisches Objekt-> Transformieren-> Vertex Shader-> Raster Konvertierung-> Fragment Shader-> Ausgabebild

### Vertex Shader
- verarbeitet alle Eckpunkte (Vertices) des 3D-Modells
- für jeden Vertex wird dieser Shader im Normalfall einmal aufgerufen
- ermöglicht eine Beeinflussung der Objektform
- Hauptaufgabe ist die Transformation der virtuellen 3D Position auf 2D koordinaten für den Bildschirm
- Input
  - Vertices aller relevanter Objekte der Szene
  - gewünschte Transformation
- Output
  - auf Bildschirm projizierte 2D Koordinaten
  - zugehörige Tiefeninformationen

Alle Transformationen die auf ein Vertex wirken und die anschließende Projektion wird als eine sogenannte MVP-Matrix zusammengefasst.

### Model View Projection
Gegeben:
- Modell als Vertices mit kartesischen 3D koordinaten und definierten Dreiecken
- Kamera (3D Position, Ausrichtung) welche das Modell betrachtet
Gesucht:
- transformierte Position
- Rendering des Modells aus Sicht der Kamera

$\rightarrow$ benötigen Abbildung von 3D-Vertexkoordinaten auf 2D-Kamerabildkoordinaten

Umsetzung:
- zuerst Transformation von Modellraum (gegebenen Koordinaten) in Weltkoordinaten (Model)
- danach Transformation in Kameraraum, für einfachere Projektion (View)
- abschließende projektion auf Kamerabildebene und Umrechnung in Bildraum (Projektion)

Model: $M=T*R*S$ (Transformation in Weltkoordinaten)

View: $V=T_V^{-1}*R_V^{-1}$ (Transformation in Kameraraum)

Kameraraum:
- Kamera sitzt im ursprung (0,0,0)
- hat keine Rotation

Projektion: P
- Bildebenenprojektion kann durch Zentralperspektivische Projektionsmatrix erfolgen
- Frustum (Kamerasichtfeld) legt fest welche Objekte im Sichtfeld liegen und somit in der Bildebene sichtbar sind

Ergebnis
- Zusammenfassung der Transformation ergibt die Model-View-Projektion-Matrix $P*V*M=MVP_{Matrix}$
- Anwendung der MVP-Matrix auf alle Vertices eines Modells $p_m$ ergibt die notwendige Bildraumprojektion des Modells: $p'_m=P*V*M*p_m$
- Vorteile: die MVP-Matrix muss nur einmal berechnet werden und kann auf alle Vertices eines Modells angewandt werden

### Zusammenfassung
- geometrische Modellierung zur Beschreibung von Objekten
- Anwendung der Transformation
- Projektion der Objekte auf den Bildschirm

## Effiziente geometrische Algorithmen und Datenstrukturen
### Bintree
- effizientes Suchen und Einfügen in eindimensionale Domänen
- logarithmische Komplexität pro Zugriff möglich
- Gefahr: lineare Komplexität, wenn nicht balanciert

analog zu Quad- und Octrees:
- typisch ost Teilung in Mitte (bisektion)
- Bereiche mit homogenem Inhalt (gleiche Farbe/ keine Elemente) werden nicht weiter unterteilt
- Komprimierungseffekt

### Quadtree
- eine (meist quadratische) Fläche kann bei Bedarf in vier gleichgroße Quadranten unterteilt werden
- Bedarf entsteht, wenn die Fläche keine homogenen Eigenschaften aufweist (z.B. bei unterschiedlich gefärbten Pixeln). D.h. Flächen (bzw Quadranten) werden solange unterteilt, bis sie homogen sind
- Anwendung
  - Geometrische 2D Objekte können in hierarischische Struktur einsortiert werden, wodurch die räumliche Suche nach diesen Objekten beschleunigt wird
  - Effiziente Speicherung von Rasterbildern wird möglich (Komprimierung, da nur strukturierte Bereiche unterteilt werden)


### Octree
Jeder Knoten hat 0 oder 8 Kindknoten. Damit wird bei Bedarf ein 3D Bereich in 8 Unterbereiche unterteilt. Geometrische Objekte (z.B. 3D Punkte) können in diese hierarchische Strukturen einsortiert werden, wodurch die räumliche Suche nach diesen Punkten beschleunigt wird.

Beispiel Punktsuche:\\
Suche einen Punkt mit Koordinaten (x,y,z) im Octree. Rekursive Suche von der Wurzel. In jedem Schritt wird einer von 8 möglichen Pfaden im Teilbaum ausgewählt -> Zeitaufwand Tiefe des Baumes O(log n)

### KD Tree
- mehrdimensionaler binärer Baum (k-dimensional)
- unterteilt z.B. abwechselnd in x-,y-, und z-Richtung (deshalb binärer Baum)
- Teilung nicht zwangsläufig mittig (wie bei Octre) -> an Daten angepasst
- jeder neue Punkt teilt den Bereich in dem er einsortiert wird; pro Hierarchiestufe stets wechsel der Teilungsrichtung
- ein Octree lässt sich auf einen kd-Baum abbilden, beide Baumarten haben daher vergleichbare Eigenschaften

KD-Baum mit der Median-Cut Strategie:\\
Der Median-Cut teilt Daten in zwei gleich großen Hälften. Damit wird der Baum garantiert balanciert und die tiefe wird minimal. Damit wird das O(log n) Verhalten garantiert. Probleme können bei lokalen Häufungen (Cluster) auftreten. Die Mediancut Strategie bewirkt eine degenerierte globale Teilung des Gesamtraumes aufgrund von lokalen Situationen. Dies wirkt sich ungünstig bei der Suche weit weg vom Cluster aus
- vollständig balanciert
- unnötige Unterteilung weit weg vom Cluster (Artefakt)

Vergleich Middlecut-Strategie:
- nicht balanciert
- keine Unterteilung weit weg vom Cluster

Praxis: Kompromiss Strategie, Mischung zwischen Median und Mitte. Bei Situations-Analyse: Explizite Abkapselung des Clusters. Außerdem: In (2D, 3D) kann man natürlich das strikt zyklische Abwechseln der Achsen aufgeben und bei fast ebenen/linearen Strukturen lokal nur noch in zwei bzw 1 Richtung(en) unterteilen!

### BSP Tree
Verallgemeinerung des kd-Baums. Trennebenen sind nicht nur achsenparallel. Unterteilung in beliebigen Richtungen, adaptiv an Modellflächen angepasst.

Beachte: Trennebenen die an einer Objektebene anliegen können dennoch weiter wegliegende Objekte schneiden.

BSP-Tree führt bei konvexen Polyedern zu entarteten Bäumen

### Hüllkörper Hierarchie
#### AABB (Axia-Aligned-Bounding-Box)
sehr einfache Abfrage (nur ein Vergleich < in jeder Koordinatenrichtung, wie bei kd-Baum) einfach zu erstellen (min, max), dafür nicht optimale Packungsdichte bei schräger Lage der Objekte.

#### OBB (Oriented Bounding Boxes)
passen sich besser der räumlichen Ausrichtungen an, lassen sich auch leicht transformieren (Rotation bei Animation). Jedoch schwieriger zu erstellen (Wahl der Richtung), komplexere Überlappungsberechnung (Transformation, Ebenengleichung).
D.h. OBB-trees werden typischerweise weniger tief, weniger räumliche Abfragen dafür wesentlich mehr Berechnungsaufwand pro Rekursionsstufe. 

#### KDOP (k-dimensional Discretly Oriented Polytopes)
Polyeder mit festen vorgegebenen Richtungen (z.B. 45 Grad). Eigenschaften zwischen AABB und OBB. Bessere Raumausnützung als AABB, weniger Transformationene als OBB.

#### BS (Bounding Spheres)
Schnelle 3D Überlappungstest (Abstand der Mittelpunkte < Summe der Radien). Langgezogene Objekte können mit mehreren Hüllkugeln (Bounding Spheres) begrenz werden um besseren Füllgrad zu erreichen. BS sind bis auf die Lage der Kugelmittelpunkte invariant gegenüber Rotation (eignen sich für Kollisionserkennung bewegter Objekte/ Echtzeit-Computer-Animation).

#### weitere Anwendungsfälle
- Kollisionserkennung in Computeranmiation (Computerspiele). Reduktion der potenziellen Kollisionspaare durch räumliche Trennung
- Beschleunigung des Echtzeitrenderings großer Datenmengen. Reduktion des Aufwands durch Culling (Weglassen)

### Ray Picking mit KD Baum
Raytracing/Strahlverfolgung, Ray picking mit KD-Baum: Vorverarbeitun, abspeicherung von Objekten (Dreiecken) im kd-Baum O(n log n)

Strahl/Objektschnitt: (als rekursive Suche im kd-Baum)

treeIntersect(p,d): Findet Schnittpunkt des Strahls (Punkt p, Richtung d) mit den im Baum gepseicherten Dreiecken und liefert die Beschreibung des nächsten Schnittpunktes bzw t=unendlich, falls kein Schnittpunkt existiert.

triangleIntersect(node,p,d): Findet Schnittpunkt des Strahles (Punkt p, Richtung d) mit einer Menge von Dreiecken in node

subdivide(node, p, d, tmin, tmax): Findet rekursiv den nächstgelegenen Schnittpunkt (kleinstes t) des Strahls (p,d) mit den Dreiecken in oder unterhalb von node im Parameterbereich tmin ...tmax

### Aufwandsabschätzung bzgl Dreiecksanzahl
Komplexität Strahl Objektschnitt (Extremfälle + typischer Fall)
1. Extremfall (beinahe) kovexes Objekt (max 2 Schnitte möglich)
  - hat ca die Komplexität einer räumlichen Punktsuche, also dem Aufwand zur Untersuchung einer Baumzelle (finden + dortige Dreiecke testen) O(log n)
2. Extremfall "Polygonnebel" (viele sehr kleine Dreiecke im Such-Volumen)
  - Annahme: alle Zellen enthalten konstante kleine Anzahl von Dreiecken -> Aufwand proportional zur Anzahl durchlaufener Baumzellen
  - Anzahl dieser Zellen ist proportional zur Länge des Strahls durchs Volumen, da der 1. Schnitt sehr wahrscheinlich mitten im Volumen oder gar nicht stattfindet -> Anzahl ist proportional zur Seitenlänge des Suchvolumens
  - bei n Dreiecken im Suchvolumen ist die Anzahl t der zu untersuchenden Zellen also ca $t=O(\sqrt{n})$ -> Suchaufwand pro Strahl folglich $O(\sqrt{n} log (n))$

typische Szene: Suchaufwand fast immer wesentlich besser als O(n). Aufwand oft zwischen beiden extremen, bei mittlerer Dichte sogar eher O(log n).

### Aufwandsabschätzung in fps
Effektiver Zeitauwand für Raytracing (RT):
- absoluter Gesamtaufwand zum Raytracing einer Szene (z.B. in ms) ist (auch) proportional zur Anzahl der Strahlen
- Annahme: 1 Strahl pro Pixel (keine Rekursion), typische Bildgröße sei 1 Mio Pixel, Szene haben mittlere Komplexität (1 Mio Polygone)
- Performancebeispiel:
  - Stand 2006, PC mit 1 CPU ca 1 Mio Strahlen/Sek -> 1 fps
  - Stand 2019, PC mit "RTX 2080 Sup23" ca 10 Giga Strahlen/Sek -> 10000 fps
- rekursives RT (Reflexion, Brechung, Schattenstrahlen etc) entsprechend mehr Strahlen, d.h. weniger Performance
- Parallelisierung einfach möglich (z.B. da Pixel voneinander unabhängig berechenbar) -> früher CPU-basiert, heute eher GPU
- 2019 mit entsprechender Hardware: rekursives Echtzeit Raytracing möglich

### Heurisitk zur Unterteilung
Surface Area Heuristic (SAH):
- Annahme: Strahl i, trifft Zelle j mit Wahrscheinlichkeit P(i,j), zudem sei $n_j$ die Anzahl Dreiecke in Zelle j,
- Aufwand für Raytracing pro Zelle proportional zur Baumtiefe ( O(log n) für balancierte Bäume, wird nicht weiter betrachtet) sowie die Anzahl der dortigen Dreiecke $n_j$; beachte $n_j$ wird hier nicht als konstant angenommen -> Gesamtaufwand für Strahl i sei also $\sum(P(i,j)*n_j)$

Heuristik: große Zellen mit wenigen Dreiecken, senken Gesamtaufwand
- Schätzung: P(i,j) ist etwa proportional zur Oberfläche einer Zelle (auf großer Oberfläche treffen mehr Strahlen auf)
- die SAH optimiert auf jeder Teilstufe im Baum das Produkt der Zellgröße mal Anzahl Dreiecke im Teilbaum. Für den kD-Baum gilt bei der Unterteilung des Bereichs D in Richtung k: $D_k = D_{k_links} + D_{k_rechts}$

Bei ungleicher Verteilung der Dreiecke (z.B. Cluster) enthalten dann große Zellen wenige oder keine Dreiecke und Baum ist nicht balanciert -> implizite Abtrennung des Clusters vom Rest des Baums (vgl Middle-Cut-Strategie)

### Behandlung ausgedehnter Objekte
Problematik: Abspeicherung ausgedehnter Objekte

Punkte haben keine Ausdehnung und können an einem eindeutigen Ort im kD-Baum abgelegt sein. Ausgedehnte Objekte (Kreise, Kugeln, Rechtecke, Dreiecke, Hüllquader, etc) können räumlich mehrere Blatt-Zellen überlappen. Ein solches Objekt müsste dann in mehreren Blattzellen einsortiert sein.

1. Ansatz: Auftrennung von Objekten, d.h. Objekte müssen an der Zellgrenze aufgeteilt werden. Einsortierung der Teilobjekte in passende Zellen. Geht gut für Dreiecke
2. Ansatz: Keine Unterscheidung zwischen Blattknoten und inneren Knoten. In diesem Ansatz werden Objekte soweit oben im Baum einsortiert, dass sie keine Zellgrenze schneiden. Nachteil: auch relativ kleine Objekte müssen in große Zellen einsortiert werden, wenn sie deren Unterteilungsgrenze schneiden
3. Ansatz: Loose Octree (überlappende Zellen): die Zellen des Octrees werden so vergrößert, dass sie mit ihren direkten Nachbarn in jeder Richtung um 50% überlappen. Objekte, die im einfachen Octree aufgrund ihrer Größe Grenzen schneiden würden, können im Loose Octree in den Zwischenknoten gespeichert werden. Ein Objekt mit Durchmesser bis zu $\frac{D}{2^L}$ kann auf der Ebene L abgelegt werden. Eine Suche im Loose Octree muss daher außer der direkt betroffenen Zelle auch die überlappenden direkten Nachbarn berücksichtigen. Dadurch vergrößert sich der Aufwand einer Suche um einen konstantne Faktor. Beachte: Die asymptotosche Komplexität (O-Notation) ist dadurch nicht beeinflusst.

# Rastergrafik
## Rasterkonversion grafischer Objekte
Algorithmus zum Zeichnen einer Strecke:\\
Endpunktkoordinaten sind nach Projektion in die Bildebene passend auf die Fensterkoordinaten skaliert und auf ganzzahlige Werte (Pixelkoordinaten) gerundet.

## Midpoint Algorithmus
- von J. Bresenham 1965 bei IBM entwickelt
- Grundidee: Effizient durch Verwendung von Ganzzahlen, Vermeiden von Multiplikation/Division sowie Nutzung einer inkrementellen Arbeitsweise

Die Linie geht zwischen den Endpunkten nicht durch ganzzahlige Gitterpunkte. Da nur ganzzahlige Pixel-Koordinaten gesetzt werden können müssten auch zwischenpunkte zuerst genau berechnet werden und dann auf ganzzahlige Pixelwerte gerundet werden. Dies ist unzuverlässig und ineffizient. Zur Herleitung des effizienten Bresenham-Algorithmus führen wir den Mittelpunkt M als Referenzpunkt ein. Fernser seinen der jeweils aktuellen Punkt P, der rechts von im liegende E (east) und der rechts oben liegende NE north-east) benannt.
- die Linie wird als Funktion $y=f(x)$ repräsentiert: $y=\frac{\delta y}{\delta x}*x+B$
- in implizierter Form: $d: F(x,y)=\delta y*x-\delta x*y+B*\delta x = 0$
- für Punkte aud der Linie wird $F(x,y)=0$
- für Punkte unterhalb der Linie wird $F(x,y)>0$
- für Punkte oberhalb der Linie wird $F(x,y)<0$

Herleitung mit Einschränkung:\\
Steigung der Linie m ($1 < m < 1$), Mittelpunkt M = Punkt vertikal zwischen zwei möglichen Pixeln E und NE. Ausgehend von bereits gesetzten Pixel P auf der Linie für den nächsten Mittelpunkt M. Für gefundenen Mittelpunkt, berechne die Distanzfunktion d. Daraus Kriterium zur Wahl des nächsten Pixels: Falls $F(x_p + 1, y_p+\frac{1}{2})>0$ wird das nächste Pixel NE, andernfalls E.

Insgesamt acht verschiedene Fälle:
1. Oktant($\delta y < \delta x$)
2. Oktant($\delta y > \delta x$)
3. Oktant($\frac{\delta y}{\delta x}<  0$)
4. Oktant($\frac{\delta y}{\delta x}< -1$)
5. -8. Oktant($\delta x < 0$)

## Anti Aliasing
Effekte der Rasterisierung: Aliasing
- Treffenstufeneffekt bei gerasterten Linien
- Regelmäßigkeiten werden verstärkt vom Auge wahrgenommen

Das Auflösungsvermögen des Auges für Punkte sei e. Strukturen wie Linien (bestehend aus vielen Punkten) werden durch Mittelwertbildung (Fitting) vom auge viel genauer als e lokalisiert. Eine Stufe wird umso eher erkannt, jelänger die angrenzenden Segmente sind.

### Grundlagen
Grundidee des Anti-Aliasing
1. Original der Linie
2. Statt der Linie wird ein Rechteck mit der Breite von einem Pixel betrachtet
3. Graustufen der darunter liegenden Pixelflächen entsprechen dem jeweiligen Überdekckungsgrad

Praktische Umsetzung mit vereinfachtem/effizienterem Algorithmus
1. Rasterkonvertierung der Linie bei doppelter örtlicher Auflösung (Supersampling)
2. Replizieren der Linie (vertikal und/oder horizontal) um Linienbreite näherungsweise zu erhalten
3. Bestimmmung des Überdeckungsgrades pro Pixel in der ursprünglichen Auflösung (Downsampling)
4. Bestimmung des Farbwertes entsprechend des Überdeckungsgrades

Problem:
- Ausgabe von Linien/Polygonen auf Rastergeräten muss auf vorgegebenem Raster erfolgen
- Farbvariation ist zwar möglich, Farbberechnung muss aber effizient erfolgen

Ohne Antialiasing:
- es erfolgt ein einfacher Test über die Pixelkoordinate
- verwendet Farbe in der Pixelmitte

Ideales Antialiasing: Hat wegen der beliebig komplexen Geometrie allgemein einen sehr/zu hohen Aufwand!

Ansatz für eine "reale Lösung"
- eine ideale Berechnung von Farbwerten nach dem Überdeckungsgrad ist allgemein beliebig aufwendig und daher praktisch irrelevant
- Gesucht werden Ansätze mit gut abschätzbarem/konstanten Aufwand
- "reales" Antialiasing beruht in der Regel auf der Verwendung von mehreren Samples pro Pixel, d.h. Berechnung dieser n Samples statt nur einem (typisch: n-facher Aufwand)

### Supersampling + Downsampling
Beim Supersampling-Ansatz wird die Graphik zunächst in höherer Auflösung gerendert (z.B. 4-fach), und dann aus den Samples ein Farbwert gemittelt (z.B. per arithmetischem Mittel).
Wie wirksam ist das Antialiasing bei 4x-Supersampling
- Ohne Anti-Aliasing kommt pro Pixel genau eine Sampleposition zum Zuge. Das Pixel wird demnach gefärbt oder nicht gefärbt: Das sind zwei mögliche Stufen.
- Bei vier Subpixeln können minimal 0 und maximal 4 Subpixel im (Makro-)Pixel gesetzt sein, d.h. es sind Intensitäten von 0%, 25%, 50%, 75% oder 100% möglich (nur 5 Abstufungen)!
- Der Zusammenhang ist einfach: Es gibt immer eine Abstufung mehr als Subpixel pro Pixel.
- Beim idealen Antialiasing entsprechend Flächenbedeckungsgrad gibt es "beliebig" viele Abstufungen (aus Aufwandsgründen aber praktisch nicht relevant).
- Gibt es eine Formabhängigkeit? Ja, z.B. bei 45° gibt es z.B. nur eine Zwischenstufe, und zwar je nach Phasenlage mit 25% oder 75% → Kante "pumpt" bei Objektbewegung.

### Supersampling + Rotated Grids
Minderung der Formabhängigkeit → Supersampling mit Rotated Grids
- Kleine Winkel zu den Achsen führen zu langen "Stufen" der digitalen Polygonkante
- Bessere Verhältnisse der Grauabstufung ergeben sich für flache Winkel, wenn statt des "ordered grid" ein "rotated grid" für das Supersampling verwendet wird.
- Rotated grids sind dafür bei anderen Winkeln etwas schlechter als das ordered grid. Dies wird aber kaum wahrgenommen, da dort die Treppen der digitalen Geraden kürzer sind.

Vorteile:
- Gute Grauabstufung bei sehr flachen Kanten zur Zeilen- oder Spaltenrichtung.
- Optimaler Winkel liegt bei ca. 20 ◦ − 30 ◦ (z.B. arctan(0.5) ≈ 26, 6 ◦ ).
- Sehr dünne Linien (dünner als 1 Pixel) bleiben auch bei Bewegung zusammenhängend bzw. sichtbar (Vermeidung von "Line Popping").


### Supersampling + Multisampling
Realisierung der Subpixelberechnung durch einen Superbackbuffer (Supersampling in entsprechend großem Buffer) oder mehrere Multisamplebuffer (Multisampling in mehrere Buffer der ursprünglichen Größe):
1. Superbackpuffer
    - Nachteil (bei rotated grid): Anpassung der Rasterkonvertierung an verschobene Positionen erforderlich
    - Vorteil: Verwendung von mehr Texturinformation (Textur wird subpixelgerecht eingetragen)
2. Multisamplebuffer
    - Mehrfachrendering in normaler Größe mit leicht versetzter Geometrie (Vertexverschiebung pro Sub-Bild)
    - Vorteil: keine Veränderung im Rendering
    - Nachteil: nur ein Texturwert pro Makro-/Sub-Pixel

Gezielter Ressourceneinsatz:
1. Kantenglättung:
    - Effizienzsteigerung durch Beschränkung auf reine Kantenglättung möglich!
    - Kanten vs. Flächen: Anzahl der Kantenpixel oft wesentlich kleiner als Anzahl der Flächenpixel
    - Aliasing bei Kanten/Mustern in Texturen schon beim Auslesen der Werte aus der Pixeltextur unterdrückbar
    - Kantenpixel bekannt als: separate Linien oder Berandung von Polygonen/Dreiecken
2. adaptives Samplen:
    - statt feste Anzahl von Samples kann die Anzahl nach dem Bedarf gesteuert werden

### Quincunx Verfahren
Quincunx → Überfilterung

Ausgangspunkt ist das 2x Multisampling mit rotated grid! Entsprechend dem Grundprinzip des Anti-Aliasings sollen Aliasingartefakte durch Erzeugung höher aufgelöster Information reduziert werden. Bei dem vorausgesetzten Muster ist der Informationszuwachs durch die doppelte Anzahl von Samples gekennzeichnet, egal wie ausgewertet wird!

Quincunx-Verfahren:
- Information für die Kantenglättung beruht nach wie vor auf 2 Subpixeln
- Entspricht einer zusätzlichen Tiefpass-Überfilterung. Durch die Unschärfe sehen Polygonkanten glatter aus.
- Harte Kanten sind gar nicht mehr möglich, dadurch wird auch "Zappeln" an Polygonrändern reduziert.
- Aber Nachteil: Texturinformation, die nur zu 2 Subpixeln gehört, wird verschmiert !

### Pseudozufälliges Supersampling
Kombinationen und Pseudozufälliges Supersampling:
- Grundsätzlich ist die Kombination von Supersampling, Multisampling und Quincunx möglich und einige Graphikkarten unterstützen solche Überlegungen in jeweils festgelegten Grenzen (ordered oder rotated grid, gemischtes Sampling, Downsampling-Ansatz). Der Gewinn hält sich bisher in Grenzen, bei unqualifiziertem Mix ergeben sich eher Nachteile.
- Bei Überwindung der für Füllrate und Bandbreite gegebenen Grenzen überwiegen die Vorteile des Supersamplings.
- Ordered grid und rotated grid weisen bei bestimmten Strukturklassen Vor- und Nachteile auf. Die verbleibenden Artefakte wiederholen sich bei großen Flächen, so dass derartige Muster vom Menschen oft als störend empfunden werden. → aus diesen und ähnlichen Überlegungen → Ansätze für die Weiterentwicklung:
    - pseudozufällige Auswahl von Abtastmustern für das Supersampling
    - nachträgliche Abminderung regelmäßiger Strukturen durch vorsichtiges Verrauschen (Rauschfilter)
    - entfernungsabhängiges Antialiasing

pseudozufällig:
- Samples können nur an n vordefinierten Positionen stattfinden (Sample-Positionsmuster).
- Je nach Methode werden daraus m Positionen für das Samplen zufällig ausgewählt (beachte: m < n)
- Anzahl der Muster als kombinatorisches Problem: m aus n (ohne Wiederholungen)

### abschließende Betrachtung zum Downsampling:
Beim Anti-Aliasing zur Glättung von Polygonkanten kommt für das Downsampling die Mittelwertbildung in Frage (lineare Filterung (2x – AA), bilineare Filterung (4x – AA)), gleichgültig ob ordered oder rotated grid. Beim pseudozufälligen Supersampling ist entsprechend der "frei gewählten" Positionen der "Subpixel" zu modifizieren (z.B. Gewichte nach Abstand der Abfragepositionen zur Makropixelposition).


## Polygonfüllalgorithmus
Ansatz:
- finde die Pixel innerhalb des Polygons
- weise ihnen Farbe zu
- dabei zeilenweises Vorgehen, pro Rasterlinie:
- für jede Polygonkante:
  - schneide die Polygonkante mit der aktuellen Bildzeile (→ $x_s$ )
  - füge Schnittpunkt $x_s$ in eine Liste ein
- sortiere Schnittpunkte der aktuellen Bildzeile in x-Richtung
- Paritätsregel: fülle die Pixel jeweils zwischen ungeradem und nächstem geraden Schnittpunkt (Pixel zwischen geraden und ungeraden Schnittpunkten aber nicht!)

Beachte: Die Schnittpunkte in floating point zu berechnen und zu runden ist ineffizient. Wir suchen, ähnlich wie beim Bresenham-Algorithmus, einen inkrementellen Ansatz mit Ganzzahl-Arithmetik.

Allgemeinere Sicht auf die Füll- bzw. Auswahlstrategie: Ein Pixel wird mit der Farbe des Polygons gefüllt, das sich rechts von ihm befindet. Sollte dort eine Kante sein, so wird die Farbe des oberen Polygons verwendet. 
Grundsätzlich könnten beliebige Richtungen als Referenzrichtung zur Farbbestimmung gewählt werden. Dann müssten die zuvor besprochenen Regeln oder der gesamte Algorithmus entsprechend angepasst werden.

Effiziente Ermittlung der Schnittpunkte von Polygonkante und Rasterzeile:
- Vorbetrachtungen:
  - Polygonkanten werden stets von unten nach oben bearbeitet
  - horizontale Polygonkanten müssen nicht bearbeitet werden (geschieht in Scanline) → im Algorithmus stets m ungleich 0
  - $d_y = y_1 - y_0$ ist stets positiv (auch nie 0)
  - $d_x = x_1 - x_0$ kann positiv und negativ sein
  - damit können 4 Bereiche unterschieden werden
- Idee
  - Berechnung von x bzw y: $y=y_0+m(x-x_0)$,$y=y_0+\frac{y_1-y_0}{x_1-x_0}(x-x_0)$,$x=x_0+\frac{1}{m}(y-y_0)$, $x=x_0+\frac{x_1-x_0}{y_1-y_0}(y-y_0)$
  - Zwar sind die x- bzw. y-Werte immer noch nicht ganzzahlig, jedoch können sie als rationale Zahlen explizit mit Zähler und Nenner repräsentiert werden.
  - Die Rundung (nächstes x oder y erreicht?) kann inkrementell ermittelt werden.
  - Die Rundungsregel für Bruchwerte hängt davon ab, ob es eine linke oder rechte Kante ist. Links wird z.B. aufgerundet (Pixel ist auf oder rechts v. der Kante).


Edge-Tabelle:
- Verkettete Liste (oder Array, siehe unten) für die nicht horizontalen Kanten.
- Sortierung nach der Scan-Line, wo die Kanten beginnen (unteres Ende, $y_0$ ).
- Innerhalb der Scan-Line wiederum Liste (nach $x_0$-Werten sortiert). Je nach Implementierung werden z.B. $x_0 , y_1$ , sowie Zähler und Nenner gespeichert.

Active-Edge-Tabelle:
- Die AET speichert alle Kanten, die die gegenwärtige Scan-Linie schneiden.
- Die Liste hat die gleiche Struktur wie eine Zeile der ET.
- Die Kanten werden gelöscht, wenn das obere Ende der Kante erreicht ist.

Bemerkung zu Scan Convert Polygon:
1. Es existiert immer eine gerade Anzahl Kanten. Bei konvexen Polygonen sind immer null oder zwei Kanten in der AET. Die Sortierung ist dadurch trivial bzw. entfällt bei konvexen Polygonen. Bei vielen Grafikbibliotheken (z.B. OpenGL) beschränkt man sich auf konvexe Polygone. Nichtkonvexe Polygone müssen daher vorher in konvexe Komponenten zerlegt werden. Dafür ist das Füllen dieser Polygone danach effizienter.
2. Dieser Teil entspricht einem Schleifendurchlauf der Prozedur EdgeScan. Die Unterscheidung zwischen linker und rechter Kante wird beim Auffüllen der Pixel gemacht.

Bemerkungen zur Effizienz:\\
Der Polygonfüllalgorithmus ist zentraler Bestandteil jeder Grafikbibliothek für Rastergrafik. Für Echtzeitanwendungen ist Effizienz essentiell. Ein Polygon belegt
meistens viel mehr Pixel als es Eckpunkte bzw. Kanten besitzt. Deshalb sind effiziente per-Pixel-Operationen besonders wichtig. Der Rechenaufwand sollte folglich möglichst vermieden werden (mit fallender Priorität):
- pro Pixel (Annahme: sehr häufig auszuführen, deshalb möglichst effizient)
- pro Rasterzeile
- pro Kante (hier sollte möglichst viel vorberechnet werden, um pro Rasterzeile bzw. Pixel Rechenzeit zu sparen)
Neben der reinen Rasterisierung des Polygons existieren Erweiterungen des inkrementellen Ansatzes für effiziente Berechnungen in der 3D-Grafik, z.B.:
- Füllen des Z-Buffers (Tiefenwertberechnung)
- lineare Interpolation beim Gouraud Shading (Farbwertberechnungen)

### Füllmuster
Füllen eines Polygons mit einem Pattern statt mit einem konstanten Farbwert
- benutze dazu BITMAPs:
  - 2-dimensionales Array
  - besteht aus M Spalten und N Zeilen
  - BITMAP = ARRAY [0 · · · M − 1, 0 · · · N − 1]

Anwendung des Backsteinmusters bei einem Polygon:
```cpp
drawPoly(Polygon poly, Pattern pat){
  foreach pixelPosition x, y in poly
    poly.set(x, y, pat[x mod pat.width, y mod pat.height]);
}
```

### Dithering
Grundidee: Ersetzen "genauer" Farbwerte durch grobe Quantisierung
- gegeben sei Tabelle (z.B. Lookup-Table) von im Output zulässigen Farben
- Durchlaufen aller Pixel (mit genauen Werten) beginnend links oben
- pro Pixel P die beste Ersetzung in Tabelle finden + setzen
- verursachten Fehler ∆ jeweils nach Schema auf unbearbeitete Nachbarpixel in der (noch) genauen Repräsentation verteilen

bei kleinen Bildern mit hoher Auflösung ist Dithering kaum wahrnehmbar

Dithering vs. Anti-Aliasing:\\ Anti-Aliasing und Dithering sind komplementär zueinander:
- Anti-Aliasing erhöht die empfundene räumlich Auflösung durch Anwendung von Zwischenwerten in der Grau-, bzw. Farbabstufung
- Dithering erhöht die Farbauflösung (verringert die empfundene Farbquantisierung) durch das Verteilen des Quantisierungsfehlers auf mehrere Pixel → Verringerung der räumlichen Auflösung.
- Beispiele zur Anwendung von Dithering:
  - verlustbehaftete Bildkompression (z.B. GIF)
  - Drucker (Halbtonverfahren) – benötigt eine feine Auflösung des Druckrasters


# Farbräume
## Motivation
Wie (und wie gut) lässt sich der visuelle Eindruck der physischen Realität durch eine Bildanzeige technisch reproduzieren? Bzw durch Computergrafik simulieren?

Ziel realistische Darstellung von Bildern:
- möglichst genaue Reproduktion von Farben und Helligkeitswerten (auf der Bildfläche)
- Ziel existiere schon bevor es Computergrafik gab (Photorealistische Malereien)

Ziel der Computergrafik:
- die technische Realisierung eines digitalen Bildes mit Hilfe des Computers aufeinem Bildschirm oder Druck,
- dazu Herleitung einer systematischen Repräsentation des Bildes als mathematisches Modell, bzw in einer Datenstruktur sowie ihre physische Reproduktion

## Farbwahrnehmung
Verschiedene Aspekte zum Verständnis des menschlichen visuellen Systems (Farbe, Helligkeit, Bild,...)
- Phänonmenologische Betrachtung: Hell- und Farbempfinden als Sinneseindruck beschreiben. Einiges kann dadurch bereits qualitativ erschlossen werden
- Phisiologie des menschlichen visuellen Systems: (Rezeptoren des Auges und neuronale Verschaltung) Dies hilft beim Verstehen der Wahrnehmung der physischen Realität und der Herleitung von exakten Farbraummodellen
- Physik: Licht als elektromagnetische Strahlung
- 
### Phänomenologisch
- Tageslicht kann als weiß bzw grau mit unterschiedlichen Helligkeiten, jedoch unbunt (farblos) empfunden werden
- Abwesenheit von Licht wird als schwarz empfunden (zB Nachthimmel)
- Regenbogen wird als bunt mit verschiedenen Farbtönen empfunden: Rot, Orange, Gelb, Grün, Cyan, Blau, Violett,...


### Farbton
- Zwischen den grob unterscheidbaren Farbtönen des Regenbogens lassen sich zwischenstufen orten, welche eine praktisch stufenlose Farbpalette ergeben
- direkt nebeneinanderliegende Farben im Farbspektrum werden als ähnlich empfunden 
- wieder andere Farben werden als sehr unterschiedlich empfunden
- mit dieser Beobachtung lassen sich Farbwerte ordnen (Dimensionen des Farbtons als eine der Dimensionen zur Beschreibung von Farbwerten)
- All diese Farben ist jedoch gemein, dass sie als sehr bunt empfunden werden (voll gesättigte Farben im Gegensatz zu Grautönen)

### Farbsättigung
- Zwischen bunten Farben und Grau lassen sich Zwischenstufen finden
- Pastelltöne sind zwar weniger bunt aber nicht völlig farblos (Farbwerte sind noch unterscheidbar)
- Grauton (keine Farbwerte unterscheidbar)
- zu jedem einzelnen bunten Farbton können Abstufungen von Pastelltönen bis zum gänzlich unbunten Grau zugeordnet werden
  - diese Abstufung nennen wir Sättigung der Farbe
  - Links maximal gesättigte Farbe, rechts völlig ungesättigte Farbe (grau)
- In jeder Zeile wird der gesättigte Farbton als nicht prinzipiell anders als die zugehörige Pastellfarbe empfunden (aber weniger bunt) nur weniger gesättigt
- 
### Helligkeitsstufen
- Zu jedem Farbton (gesättigt oder nicht) können unterschiedliche Helligkeitsabstufungen bis zum tiefen Schwarz zugeordnet werden
  - links maximale Helligkeit, rechts dunkelster Wert (schwarz)
  - in jeder Zeile werden die hellen Farbtöne als nicht prinzipiell anders als die zugehörigen dunkleren Farbtöne empfunden
  - im schwarzen sind ebenfalls keine Farbtöne mehr unterscheidbar

### Zusammenfassung
damit haben wir phänomenologisch drei unabhängige Richtungen identifiziert, die wir den Farbeindrücken zuordnen können:
- Farbton (Hue)
- Farbsättigung (Saturation)
- Helligkeit (Lightness)

## Das Modell der Farben
> Definition DIN 5033: Farbe ist die Empfindung eines dem Auge strukturlos erscheinenden Teils eines Gesichtsfeldes, durch die sich dieser Teil bei einäugiger Beobachtung mit unbewegtem Auge von einem gleichzeitig gesehenem, ebenfalls strukturlos angrenzendem bezirk allein unterscheidet.
> Farbe (in unbunter Umgebung) ist durch Helligkeit, Buntton und Sättigung eindeutig bestimmt. Dieses oder ein ähnliches dreidimensionales (3D) Modell ist für das Verständnis der Farbe erforderlich


### HSL Farbraum
bzw HSB, HSV, HSI

Mit den gewonnen Erkenntnissen wir der HSL Farbraum definiert:
- Farbton: **H**ue
- Sättigung: **S**aturation
- Helligkeit: **L**ightness/**B**rightness/**V**alue/**I**ntensity
Da sich die Dimension des Farbtons periodisch wiederholt wird das System oft als Winkelkoordinate eines Polarkooridnaten-Systems in der HS-Ebene, bzw dreidimensional als Zylinderkoordinaten HSl darstellt.

Darstellungsformen: Die Darstellungsform des HSL Farbraums ist nicht fest vorgeschrieben. Eine Darstellung als (Doppel)-Kegel oder sechseitige (Doppel-) Pyramide ist ebenso möglich.

Der HSl Farbraum entspricht zumindest grob unserer Farbwahrnehmung. Daher eignet er sich zur intuitiven und qualitativen Einstellung von Farben in Illustrationsgrafiken
- Relative Skala 0..255
- Quantisierbarkeit der Farben und Helligkeit z.B. beruhend auf physiologischen Messungen
- Bezug zur Physik des Lichtes (Energie, Spektrum)

### RGB Farbraum
> Hypothese, dass Farbsehen auf drei Arten von Sinneszellen beruht (rot, grün, blau) ~ T. Young, 1807

> ein und diesselbe Farbwahrnehmung kann durch unendlich viele unterschiedliche Farbreize erzeugt werden, Farbwahrnehmungen sind durch drei beliebige, linear unabhängige Größen darstellbar. ~ Graßmann, 1853

Im menschlichen Auge befinden sich Zäpfchen, welche mit unterschiedlicher Empfindlichkeit auf die verschiedenen Wellenlängen des Lichtes reagieren. Es gilt: gleicher Reiz heißt gleiche Farbwahrnehmung

Beispiel für Reizung durch monochromatisches Licht (Laser) einer bestimmten Stärke:
- $r=0,2R(\lambda)4
- $y=0,5R(\lambda)+0,3G(\lambda)$
- $g=0,2R(\lambda)+0,5G(\lambda)$
- $b=0,02B(\lambda)$

Farberzeugung durch Mischung:
$$1,9r + 0,6g = 0,38R(\lambda)+0,12R(\lambda)+0,3G(\lambda)=0,5R(\lambda)+0,3G(\lambda) = y$$

geschichtliche/physikalische Aspekte:
- Sonnenlicht ist eine Mischung von einzelnen Farben
- Korpuskular- bzw Emissiontheorie
- Spektralfarben sind objektive Eigenschaften des Lichtes
- Prisma spaltet das weiße (Sonnen-) Licht in Spektralfarben
- durch Sammellinse lässt sich aus dem Spektrum wieder weißes Licht erzeugen
- kammartige Ausblendung führt zu bunten Mischfarben

Additive Farbmischung in RGB:\\
Mit den Grundfarben Rot, Grün und Blau können weitere bekannte Farben additiv gemischt werden (Rot+Blau=Magenta). Weitere Zwischenfarbtöne können durch kontinuierliches Variieren der Anteile der Grundfarben gemischt werden (alle Pastellfarben und Graustufen)

Bestimmen der Anteile der Mischfarben:\\
- zur Mischung beliebiger Farben verwenden wir die experimentiell bestimmten drei Empfindlichkeitskurven: R,G,B und zugehörige Lichtquellen r,g,b
- alle 3 Lichtquellen zusammen ergeben weiß wahrgenommenes Licht: r=g=b=1~weiß (muss gut abgestimmt werden -> Weißabgleich)
- wir können damit einen dreidimensionalen Farbraum (RGB-Farbraum) aufspannen
- die Lage einer monochromatischen Lichtwuelle $x(\lambda_0)$ in diesem RGB Farbraum lässt sich wie folgt berechnen: $x(\lambda_0)=p*r+\gamma*g+\beta*b$
- Achtung: die Lösung hängt von den Wellenlängen der verwendeten Grundfarben r,g,b (Primärvalenzen) ab. Nimmt man andere Grundfarben, ergeben sich andere Werte für $p,\gamma,\beta$
- RGB ist nicht gleich RGB! Man muss "eigentlich" immer die Wellenlängen der verwendeten Grundfarben r,g und b mit angeben!

Innere Farbmischung: $F=p*r + \gamma*g + \beta*b$

Äußere Farbmischung:\\
die gemischte Farbe Cyan wird zwar als derselbe Buntton wie die Referenzfarbe F wahrgenommen, jedoch weniger gesättigt. Um die beiden Farben gleich aussehen zu lassen wird der Referenzfarbe F etwas Rot beigemischt. Damit sind beide Farben gleich ungesättigt. Das Verfahren wird äußere Farbmischung genannt: $F=p*r + \gamma *g - \beta *b$.
Um die aus Blau und Grün gemischte Farbe Cyan voll gesättigt aussehend zu lassen, müsste Rot aus der Mischfarbe subtrahiert werden. Dies ist allerdings technisch nicht realisierbar. Durch die negative Farbvalenz wird das Modell jedoch theoretisch konsistent und es lassen sich alle Farben durch Mischen von Rot, Grün und Blau darstellen. Daraus wird ein vollstänfiges RGB-Farbmodell abgeleitet.

Idee:
- es werden drei linear-unabhängige Größen benötigt
  - zur beschreibung der Farbempfindung
  - zur (technischen) Reproduktion der Farbempfindung
- zunächst werden folgende Werte gewertet
  - die additive Mischung als Reproduktionsmethode
  - drei Primärfarben Rot, Grün, Blau
- drei linear unabhängige Größen spannen stets einen 3D Raum auf
  - die RGB Werte werden den drei ortogonalen Achsen dieses Raumes zugeordnet

Darstellung des RGB Farbraums:
- alle mit drei Farblichtquellen technisch (additiv) erzeugbaren Farben liegen innerhalb eines Würfels
- Im Koordinatenursprung befindet sich Schwarz, diagonal gegenüber weiß.
- auf der Raumdiagonalen liegen dazwischen die Graustufen

Bei entsprechender Normierung liegen die vom RGB Farbsynthesesystem erzeugbare Farben im Einheitswürfel. Zunächst wird der Begriff Intensität eingeführt: $I=\frac{R+G+B}{3}$. Der Ausschnitt aus der Ebene konstanter Intensität, der im Einheitswürfel liegt, wird im Interesse der einfachen Darstellung als Farbebene (Farbtafel) genutzt. Dabei bleibt die Ordnung der Farbvalenzen erhalten. Die Länge |F| der Farbvalenz bzw die Intensität geht verloren.
Die in der Ebene konstanter Intensität liegenden Werte definieren die Chrominanz durch welche die Farbwertanteile erfasst werden (zwei reichen aus da 2D). Es kann auch die Projektion der Ebene auf RG (grau überlagert) als Farbtafel genutzt werden, ohne die Ordnung der Farborte zu stören. Vorteil: orthonoales rg-System

RGB Farbtafel:\\
Alle Farben gleicher Buntheit (unterscheiden sich nur in der Länge von F) führen zum gleichen Farbort, der durch die Farbwertantwile r,g,b beschrieben wird:
$$r=\frac{R}{R+G+B}, g=\frac{G}{R+G+B}, b=\frac{B}{R+G+B} \leftrightarrow r+g+b=1$$

Aus dem rechten Teil der Gleichung folgt mit $b=1-r-g$, dass sich die Buntheit allein durch r und g darstellen lässt (entspricht $\R^2$).
Die Farbwertanteile lassen sich bei bekanntem Farbort in der Farbtafel nach der angegebenen Konstruktionsvorschrift ermitteln oder direkt ablesen.


### CIE System
Um eine Relation zwischen der menschlichen Farbwahrnehmung und den physikalischen ursachen des Farbreizes herzustellen, wurde das CIE-Normvalenzsystem von der Internationalen Beleuchtungskommission (CIE) definiert. Es stellt die Gesammtheit der wahrnehmbaren Farben dar.

Farbkörperunterschiede:\\
Es finden sich Unterschiede welche Farbbereiche nach dem CIE Normalvalenzsystem von den jeweiligen Systemen dargestellt werden können:
- menschliche Farbwahrnehmung ca 2-6 Mio Farben
- Monitor: ca 1/3 davon. Bei Monitoren wird die additive Farbmischung verwendet, da die einzelnen Lichtquellen aufsummiert werden.
- Druckprozess: meist deutlich weniger Farben. Bei Druckernwerden einzelne Farbschichten auf Papier gedruckt und das resultierende Bild wird über die subtraktive Farbmischung bestimmt.

Subtraktive Farbmischung:\\
Je nachdem welche Farbe ein Material hat, werden entsprechende Farbanteile absorbiert oder reflektiert. Eine gelbe Oberfläche sieht gelb aus, das sie das Blau aus weißem Licht absorbiert, aber Rot und Grün reflektiert.

Achtung: Dies gilt nur für die Bestrahlung mit weißem Licht. Wird beispielsweise ein gelbes Blatt mit blauem Licht bestrahlt, dann wirkt es schwarz, da das blaue Licht vom gelben Blatt absorbiert wird.

# Licht \& Reflexion

