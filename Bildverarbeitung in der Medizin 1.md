# Bildrepräsentation und Bildeigenschaften
## Ortsbereich
kontinuierliche Bild: Definition als 2D-Grauwertfunktion $g(x,y)\in \mathbb{R}$

Digitalisierung: Quantisierung der Grauwerte
$q(g)=[\frac{g-g_{min}}{g_max}-g_{min} *q_{max}]_{mathbb{N}}$ mit $q_{max}=2^N-1$

4-Nachbarschaft: gemeinsame Kanten
8-Nachbarschaft: gemeinsame Kanten oder Ecken

- Pixel: Jeder Abtastwert $q(m,n)$ entspricht einem quadratischen Bildelement (Pixel) mit homogenem Grauwert.
- Falschfarbendarstellung: $g$ wird als Index in eine Farbtabelle (Video Lookup Table - VLT) behandelt -> Kontrasterhöhung
  
Pfad
- Zwei Pixel $P_A(m_A,n_A)$ und $P_B(m_B,n_B)$ sind durch einen Pfad verbunden, falls es eine Folge von benachbarten Pixeln $(P_A,P_1, ...,P_B)$ gibt, für die eine Homogenitätsbedingung (z.B. alle Pixel haben gleichen Grauwert, d.h. $g(P_A)=g(P_1)=...=g(P_B))$ gilt.
- Offener Pfad: $P_A\not = P_B$
- Geschlossener Pfad: $P_A = P_B$
- Pfade sind an Nachbarschaftsdefinitionen gebunden!

Zusammenhang: Eine Menge von Pixeln ist zusammenhängend, wenn zwischen zwei beliebigen Pixeln ein Pfad existiert.

Rand:
- Der Rand einer zusammenhängenden Pixelmenge $M$ ist eine Folge von Pixeln in $M$, die mindestens einen Nachbarn haben, der nicht zu $M$ gehört.
- Die Randpixel gehören somit zu $M$ dazu.
- Der Rand ist ein zusammenhängender Pfad und deshalb auch an eine Nachbarschaftsdefinition gebunden.
- Rand in 4-Nachbarschaft zum Hintergrund -> zusammenhängender Pfad gemäß 8-Nachbarschaft
- Rand in 8-Nachbarschaft zum Hintergrund -> zusammenhängender Pfad gemäß 4-Nachbarschaft

Distanzmaße:
- Euklidische Distanz (Länge der direkten Verbindung): $D_E=||P_1 - P_2||_2=\sqrt{(m_1-m_2)^2 + (n_1+n_2)^2}$
- Manhatten Distanz (City Block, Länge des kürzesten Pfades unter 4er-Nachbarschaft): $D_4=||P_1-P_2||_1=|m_1-m_2| + |n_1-n_2|$
- Schachbrett-Distanz (Länge des kürzesten Pfades unter 8er-Nachbarschaft): $D_8=||P_1-P_2||_{\infty}= max\{|m_1-m_2|, |n_1-n_2|\}$
- Schachbrett D. $\leq$ Euklidische D. $\leq$ Manhatten D.

Diskretisierung im Ortsbereich
- Multiplikation des Bildes mit der Abtastfunktion ( Dirac-Gitter) = Faltung im Ortsfrequenzbereich mit 2D-FT der Abtastfunktion (Dirac-Gitter)
- Periodifizierung im Ortsfrequenzbereich mit den Intervallen $\frac{1}{\Delta x}$ bzw. $\frac{1}{\Delta y}$
- Aliasing (spektrale Überlappung): Vermeidung, wenn $f_{x,max}\leq\frac{1}{2*\Delta x}$ und $f_{y,max}\leq\frac{1}{2*\Delta y}$, dann ist Rekonstruktion mit idealem 2D-Rechteckfilter möglich

Diskrete 2D-Faltung
- nicht zyklische vs. zyklische Berechnung
  - Fortsetzung der Bildpunkte außerhalb der Bildgrenzen von $g_1(m,n)$
  - Nicht zyklische Fortsetzung durch Anfügen von Nullen
  - Zyklische Fortsetzung durch periodisches Anfügen von Pixeln (von anderem Bildende)
- Indizierung des Operators
  - Festlegung des Referenzpunktes im Operator
  - positiv indiziert: bei $h(0,0)$
    - Theoretisch konsistent mit der Faltungseigenschaft der 2D - DFT
  - symmetrisch indiziert: in der Operatormitte
    - Genau genommen nicht konsistent mit der Faltungseigenschaft der 2D - DFT
  - jew. um $180°$ gedrehter Operator
- Umfang (Grenzen) der Operatoranwendung auf das Eingangsbild $g_1(m,n)$
  - verschiedene Berechnungs-Modi
  - full: die Berechnung erfolgt, solange mindestens ein Pixel des Bildes von $h(m,n)$ überdeckt wird.
    - Folglich ist das Ausgangsbild $g_2(m,n)$ größer als das Eingangsbild $g_1(m,n)$.
  - same: die Berechnung erfolgt so, dass das Ausgangsbild $g_2(m,n)$ genauso groß wie das Eingangsbild $g_1(m,n)$ ist.
  - valid: Die Berechnung erfolgt nur, wenn $h(m,n)$ vollständig (d.h. $K\times L$) Pixel des Eingangsbildes $g_1(m,n)$ überdeckt.
    - Folglich ist das Ausgangsbild $g_2(m,n)$ kleiner als das Eingangsbild $g_1(m,n)$.

Wiener-Filter = Minimum Mean Square Error Filter
- unter der Annahme, dass Rauschen und Bild unkorreliert sind
- $H_W=\frac{H^*}{|H|^2 + \frac{S_{\eta}}{S_f}}$

# Bildvorverarbeitung

## Bildfehler
Pin Cushion Verzerrung
Barrel Verzerrung
Verzerrung durch Bewegung
Fokusierungsunschärfe
Verrauschen
Salz und Pfeffer Rauschen

## Bildrestauration
Beseitigen von Störungen / Verzerrungen, die bei der Bildaufnahme entstanden sind
- = Beseitigen von deterministischen Störungen, die i. A. bei der Bildaufnahme entstehen
- mögliche Ursachen: 
  - Aliasing
  - Verschmieren (Blurring) durch Defokussierung und/oder Bewegung
  - Geometrische Verzerrung
  - Pixel- oder Zeilenfehler
- Ursachen von Verschmierungen
  - Defokussierung
  - Bewegungsartefakte (z.B.: Horizontale Kamerabewegung über 5 Pixel auf dem Kamerasensor während der Belichtungszeit:

Geometrische Verzerrungen
- Entzerrung mittels Matrixmultiplikation
- Affine Transformation
  - Translation $\hat{r}= \begin{pmatrix}x^* +dx\\ y^* +dy\\ 1\end{pmatrix}=\begin{pmatrix} 1 & 0 & dx \\ 0 & 1 & dy \\ 0 & 0 & 1 \end{pmatrix} \begin{pmatrix} x^*\\ y^*\\ 1\end{pmatrix}= T^{*} * \hat{r}^{*}$
  - Skalierung $\hat{r}=\begin{pmatrix} S_x*x^* \\ S_y* y^*\\1 \end{pmatrix} =\begin{pmatrix} S_x & 0 & 0 \\ 0 & S_y & 0 \\ 0 & 0 & 1 \end{pmatrix} \begin{pmatrix} x^*\\ y^*\\ 1\end{pmatrix}=T^{*} * \hat{r}^{*}$
  - Scherung $\hat{r}=\begin{pmatrix} x^* +b_x*y^* \\ b_y*x^*+y^*\\ 1 \end{pmatrix} =\begin{pmatrix} 1 & b_x & 0 \\ b_y & 1 & 0 \\ 0 & 0 & 1 \end{pmatrix} \begin{pmatrix} x^*\\ y^*\\ 1\end{pmatrix}=T^{*} * \hat{r}^{*}$
  - Rotation $\hat{r}=\begin{pmatrix} cos\ \alpha*x^* - sin\ \alpha*y^* \\ sin\ \alpha*x^* + cos\ \alpha*y^*\\ 1 \end{pmatrix} =\begin{pmatrix} cos\ \alpha & -sin\ \alpha & 0 \\ sin\ \alpha & cos\ \alpha & 0 \\ 0 & 0 & 1 \end{pmatrix} \begin{pmatrix} x^*\\ y^*\\ 1\end{pmatrix}=T^{*} * \hat{r}^{*}$
  - Eigenschaften: 
    - bestimmt durch 6 Parameter
    - Linear
    - Geraden bleiben Geraden
    - Parallele Geraden bleiben parallel
    - Distanzverhältnisse auf Geraden bleiben erhalten
  - Matrix-Multiplikation ist im Allgemeinen nicht kommutativ, d.h.: Reihenfolge beachten! Aus Ausführungsreihenfolge $T_1,T_2,...,T_{n-1},T_n$ wird Multiplikation $\hat{r}=T_n,T_{n-1}...,T_2,T_1$ 
- Abbildung von 3 Passpunkten (affine 3-punkt-transformation)
  - $\hat{r}=\begin{pmatrix}x\\ y\\ 1\end{pmatrix}= T^*_A*\hat{r}^*=\begin{pmatrix} a_{11} & a_{12} & a_{13}\\ a_{21}& a_{22}& a_{23} \\ 0 & 0 & 1\end{pmatrix}\begin{pmatrix} x^* \\ y^* \\ 1\end{pmatrix}$
  - Rekonstruktion der Inverser: $T_A=\frac{1}{a_{11}a_{22}-a_{12}a_{21}} * \begin{pmatrix} a_{22}& -a_{12}& a_{12}a_{23}-a_{13}a_{22}\\ -a_{21}& a_{11}& a_{13}a_{21}-a_{11}a_{23}\\ 0 & 0 & a_{11}a_{22}-a_{12}a_{21} \end{pmatrix}$

Projektive Transformation
- Abbildung von 4 Passpunkten: $\hat{r}=\begin{pmatrix}x\\ y\\ 1\end{pmatrix}=T^*_p * \hat{r}^*=\begin{pmatrix} a_{11}& a_{12}& a_{13}\\ a_{21}&a_{22}&a_{23}\\ a_{31}&a_{32}& 1\end{pmatrix}\begin{pmatrix}x^*\\ y^*\\ 1\end{pmatrix}$
- Eigenschaften: 
  - bestimmt durch 8 Parameter
  - Nur mit homogenen Koordinaten linear darstellbar
  - Geraden bleiben Geraden

Radialsymmetrische Transformation
- Rotationssymmetrisch (Pin Cushion, Barrel Verzerrung)
- in Polarkoordinaten $R=\frac{1}{1+k*R^*}*R^*$
  - $k>0$: Barrel Transformation
  - $k<0$: Pin Cushion Transformation
- Eigenschaften: 
  - Nicht linear!
  - Radialsymm. Verzerrungen i. A. bei Linsen-Systemen

Interpolation auf 2-Support Grid
- Lineare Interpolation: $g(m,y_0)=g(m,n)+\frac{y_0-n}{(n+1)-n}*[g(m,n+1)-g(m,n)]$
- Nearest Neighbor, Ideale Interpolation, Kubische Interpolation
- Nur die Pixel im jeweiligen SupportGrid sind für die Berechnung von $g(x_0,y_0)$ relevant
- 1D: $g_1(x)=w(x)*g(x)=\sum_m w(x-m)*g(m)$ mit $m\in\mathbb{Z}$
- 2D: $g_1(x,y)=w(w,y)**g(x,y)=\sum_m \sum_n w(x-m,y-n)*g(m,n)$
- Interpolationsbedingung: $w(0)=1$, $w(|m,n|\geq 1)=0$

## Bildregistrierung
Anpassung (Transformation) von Zielbildern auf ein Referenzbild (z.B. mit Ziel der Bildfusion)
- Passpunktbasierte registrierung
  $\begin{pmatrix} x_1\\ x_2 \\ x_3\\y_1\\ y_2\\ y_3\end{pmatrix}=\begin{pmatrix} x_1&y_1&1&0&0&0\\ x_2&y_2&1&0&0&0\\ x_3&y_3&1&0&0&0\\ 0&0&0&x_1&y_1&1\\ 0&0&0&x_2&y_2&1\\ 0&0&0&x_2&y_3&1\end{pmatrix} * \begin{pmatrix} a_{1,1}\\ a_{1,2}\\ a_{1,3}\\ a_{2,1}\\ a_{2,2}\\ a_{2,3} \end{pmatrix}$ 
- Passpunktunabhängige registierung
  - normierte Kreuzkorrelation
  - Fourier-Mellin-Transformation 

## Bildverbesserung
Verbesserung des subjektiven Wahrnehmung
Anhebung der für den Betrachter (diagnostisch) relevanten Bildinformation

Pixelbasierte Kontrastverbesserung (Differenz zwischen min. und max. Grauwert erhöhen)
- Intensitäts-Transformatins-Kennlinie (Gradiationskurve)
- Grauwertspreizung -> Histogramm $q=[q_{min}+\frac{g-g_{min}}{g_{max}-g_{min}}*(q_{max}-q_{min})]_{\mathbb{N}}$
- Clipping durch Intensity Transformation Function (ITF)
- Logarithmus Transformation $q=[q_{max}*\frac{ln(g+1)}{ln(g_{max}+1)}]_{\mathbb{N}}$
  - Spreizung niedriger (dunkler) GW
  - Stauchung hoher (heller) GW
- Gammakorrektur (Potenztransformation) $q=[q_{max}(\frac{g}{g_{max}}^y)]_{mathbb{N}}$
  - steile kurve -> spreizung der jew. grauwerte
  - flache kurve -> stauchung der jew. grauwerte
- Histogramm-Linearisierung $q_i=\lceil N_q*\frac{\sum_{k=0}^i h(k)}{M*N} \rceil_{mathbb{N}} -1$
  - Spreizung häufiger GW, Stauchung seltener GW

Rauschunterdrückung (Tiefpassfilter)
- Prinzip $g_{TP}(x,y)=g(x,y)** h_{TP}(x,y)$
- gegen Gauß/ Salz&Pfeffer- Rauschen
- Mittelwertfilter $h(x,y)=rect(\frac{x,s_x},\frac{y}{s_y})*\frac{1}{s_x*s_y}$
- Idelaer Tiefpass (erzeugt Ringing-Artefakte aufgrund der Nebenmaxima der entsprechenden Ortsbereichsfunktion (2D-si-Funktion, rotationssymmetrisch))
- Gauß Tiefpass (minimales Zeitdauer-Bandbreite-Produkt)
- Binominal Filter $b=\frac{1}{n}[n\ (n-1)\ ...]$ (ganzzahlige Approximation des Gauß-Filter)
- Medianfilter (sortierte Umgebungspixel)
- nichtlinearer Median-Filter $g(x,y)=median\{g(x',y')\}$
  - Bildung des Medians aller Grauwerte der Pixel in der Umgebung von $(x,y)$
  - gehört zu den Rangordnungsfiltern
  - besonders für Salz- und Pfeffer-Rauschen geeignet
  - starke gerade Kanten bleiben erhalten

Hervorhebung von Kanten (Hochpassfilter)
- Lineare Hochpass Filter: Mittelwert, Ideal, Gauß
- Gradientenbild (vertikal, horizontal, kombiniert)
  - Problem: Rauschempfindlichkeit schlecht
  - geringe Verschiebung
- symmetrische Gradientenschätzung
  - keine Verschiebung im Gradientenbild
  - etwas robuster gegen Rauschen
- Prewitt-Operator (robuster gegen Rauscheinflüsse)
- Sobel-Operator (äquivalent zum Prewitt-Operator, jedoch Mittelwert-Filter durch Binomial-Filter ersetzt)
- Laplace-Operator $\Delta g(x,y)=\frac{\delta^2 g}{\delta x^2}+\frac{\delta^2 g}{\delta y^2}$
  - ist sehr rauschempfindlich
  - ist richtungsunabhängig
  - vorheriges Gauß-Filter führt zu ,Laplacian of Gaussian'-Filter (LoG) zur Erhöhung der Robustheit gegen Rauschen

# Segmentierung
Unterteilung des Bildes hinsichtlich der Struktur in einzelne Bildabschnitte (Segmente)
- Unterteilung des Bildes in Teilbereiche (Regionen, Segmente, Bildobjekte) mit gleichen Eigenschaften
- Trennung Vordergrund / Hintergrund
- Extraktion von Objekten (Organe, Zellen, ...)

Eigenschaften:
- Vollständigkeit: jedes Pixel wird mindestens einem Segment zugeordnet
- Überdeckungsfreiheit: ein Pixel wird maximal einem Segment zugeordnet
- Zusammenhang: jedes Vordergrundsegment bildet ein zusammenhängendes Objekt


## Pixel- bzw. histogrammbasierte Segmentierung
Schwellwertsegmentierung
- festlegen von Schwellwert -> trennung von Vorder- und Hintergrund
- durch Gauß Schnittpunkte oder Otsu, Histogramm
- bei Rauschen zuvor Filtern (z.B. Median)
- bei Shading zuvor Filter (z.B. Median)
- optimaler Schwellwert nach Otsu
  - Normierung der Häufigkeit $h(g)$ -> Wahrscheinlichkeit $p(g)
  - Wahrscheinlichkeit eines Grauwerts $g: p(g)=\frac{h(g)}{M*N}$
  - Wahrscheinlichkeit der Klassen $C_1$ und $C_2$: $P_{C_1}(S)=\sum_{g=0}^S p(G)$, $P_{C_2} p(g)=1-P_{C_1}(S)$

## Regionen-basierte Segmentierung
Annahme: Die Pixel eines Segmentes erfüllen ein gegebenes Homogenitätskriterium (Ähnlichkeitskriterium)!

Region-Growing
1. Festlegung eines Saatpunktes (manuell oder automatisch) $P_S$ innerhalb des Segments
2. Festlegung eines Homogenitätskriteriums $q$ z.B. GW variieren um 20 Stufen um den Grauwert des Saatpunktes
3. Bestimmung aller Nachbarpixel um die aktuelle Region
    - 1. Region = Saatpunktregion) unter 4- bzw. 8-Nachbarschaft
4. Hinzufügen aller Nachbarpixel P zur aktuellen Region für die gilt: $q(P,P_S)=1$ (d.h. Homogenitätskriterium erfüllt ist)
5. Wiederholen von Schritt 3-4 bis keine Nachbarn mehr hinzugefügt werden

Region-Mergin
1. zu Beginn: Jedes Pixel ist ein Segment.
2. Zwei benachbarte Segmente werden zusammengefasst, wenn sie eine Homogenitätsbedingung erfüllen.
3. Die Segmentierung ist beendet, wenn nichts mehr zusammengefügt werden kann

Split-and-Merge
1. Gesamtes Bild ≙ einem Segment
2. Jedes Segment wird (rekursiv) in 4 gleich große Teile (Split) zerlegt, falls es einer Homogenitätsbedingung (HB) nicht genügt
3. Zerlegung endet, falls alle Segmente homogen sind
4. Zusammenfassung (Merge) benachbarter homogener Segmente

## Kantenbasierte Segmentierung
Schwellwertsegmentierung des Gradientenbildes
- Originalbild -> Tiefpassfilter -> Gradientenbild -> Schwellwertsegmentierung -> Thinning
- segmentierter Sobel-Gradient

Canny-Edge-Operator
- non-maxima-suppression (thinning)
- echte Kanten möglichst zuverlässig detektieren
- Kantenposition zuverlässig detektieren
- Anzahl falscher Kanten minimieren
1. Tiefpassfilterung des Bildes mit Gauß-Filter der Varianz $\delta$
2. Berechnung des Gradientenbildes und der Gradientenrichtung
3. Non-Maximum-Suppression: Extraktion aller lokalen Maxima im Gradientenbild in Gradientenrichtung
4. Extraktion der starken Kantenpixel
5. Extraktion der schwachen Kantenpixel
6. Auffüllen der Lücken in den Kantenzügen mit Lückenpixel
- Merkmale:
  - Empirische Bestimmung der Parameter $\delta$, $S_1$ und $S_2$
  - Optimal für ideale Kanten unter Gauß-förmigem Rausch- und Defokussierungseinfluss
- Ergebnis: Binärbild (Kanten als Vordergrund)

## Wasserscheidentransformation
- Interpretation des Bildes als 2D-Funktion („Gebirge“)
- Wasserscheiden („Gebirgskämme“) trennen in unterschiedliche „entwässernde“ Senken
- Flutungs-Algorithmus
- Kantendetektion: WST auf Gradientenbild berechnen
- Problem: oft Effekt der Übersegmentierung

## Modellbasierte Segmentierung 
Einbringen von Modellinformationen in den Segmentierungsprozess (Detektion von Bildobjekten)

Template Matching
- Vorgabe eines Musters, das Form und Orientierung der Segmente im Bild bestimmt
- Bestimmung des normierten Kreuzkorrelationskoeffizienten
- Ergebnis: Segmente befinden sich an den lokalen Extrema 

Hough Transformation
- Hough Transformation von Geraden -> Hesse-Normalform
  - $cos\ \phi*x + sin\ \phi*y =d$
  - Koordinaten-Transformation $H_K$ in den Hough-Raum (Parameterraum)
  - Transformation aller Vordergrundpixel von $g$ in die entsprechenden Kurven im $(\phi,d)$-Parameterraum für alle
  - Suche nach Punkten im $(\phi,d)$-Raum, an denen sich besonders viele $H_k$-Kurven schneiden
- für Kreise/Ellipsen Kreisgleichung $(x-x_c)^2 + (y-y_c)^2=r^2$

# Morphologische Operationen
Anwendung: 
- Veränderung von Formen
- Extraktion von Formmerkmalen
- Detektion von bekannten Formen

## Grundoperationen
- Dilatation $\oplus$: $B\oplus M$
  - vergrößert Objekte
  - verbindet Strukturen
  - füllt Löcher
  - glättet Segmentrände
- Erosion $\ominus$: $B\ominus M$
  -  verkleinert Objekte
  - entfernt Strukturen „kleiner“ als
  - vergrößert Löcher
- Dualität: $B\oplus M=\overline{\overline{B}\ominus M}$, $B\ominus M=\overline{\overline{B}\oplus M}$ 
- Opening: Erosion & Dilatation  $B\circ M= (B\ominus M)\oplus M$
- Closing: Dilatation & Erosion  $B\circ M= (B\oplus M)\ominus M$



## Bestimmung von Formmerkmalen
Berechnung des Randes: 
- $R_{4/8}=B\backslash (B\ominus M_{4/8})$
- Erosion mit Strukturelement entfernt alle Pixel in deren 4/8-Nachbarschaft sich mindestens ein Hintergrundpixel befindet
- Rand ergibt sich durch Subtraktion vom Original
- Der Rand gehört also zum Objekt und ist nicht die Umrandung drum herum

Hit-or-Miss-Operator
- Detektion von def. Objekten (d.h. def. Vordergrund vor def. Hintergrund)
1. Bestimmung aller Positionen (Instanzen) an denen der Vordergrund des Objektes liegen kann
2. Bestimmung aller Positionen an denen der erwartete Hintergrund des Objektes liegen kann
3. Schnittmenge beider Ergebnisse
- Hit-Operator $M_H$ und Miss-Operator $M_M$ (jew. gegenteilig zueinander)
- 0, 1, X (x für nicht-beachtet)

Iterative Distanztransformation
- Allen Pixeln des $k$-ten Randes werden die Grauwerte $k-1$ zugewiesen. (Alternativ ist auch $k$ möglich)
- Distanztransformation ersetzt jeden Pixel (GW) innerhalb eines Objektes durch seinen kürzesten Abstand zum Objektrand
- Iterative Bestimmung durch wiederholte Bestimmung des Objektrandes

Skelettierung
- Definition mittels maximal eingeschriebener Kreise
- Der digitale Kreis um das Skelettpixel muss vollständig innerhalb des Segmentes liegen.
- Für ein von einem Kreis berührtes Randpixel darf es keinen Kreis mit größerem Radius geben, der die Bedingung 1 erfüllt, damit der Mittelpunkt ein Skelletpixel ist.
- Skelett besteht aus den Zentren aller maximal eingeschriebenen Kreise
- Kann aus den „Gebirgskämmen“ des distanztransformierten Bildes gewonnen werden.
- Anwendung: Zeichenerkennung, Datenreduktion, Merkmalsextraktion für Klassifizierung

Morphing
- Lineare Interpolation zwischen den Distanzwerten von zwei Segmenten
- Vorzeichenbehaftete Distanztransformation -> Linearkombination $A_i=i*A_1+ (1-i)*A_2$

# Merkmalsextraktion und Klassifikation
- Merkmalsextraktion: Erfassung von Merkmalen (Eigenschaften) zusammenhängender Bildobjekte (Segmente)
- Merkmal: Skalar, welcher einen bestimmten Aspekt der Objektbedeutung beschreibt
- Klassifikation: Zuordnung von Bildobjekten
- Merkmale werden für jedes zusammenhängende Objekt im Bild bestimmt

## Regionenbasierte Merkmale
Merkmale werden vom Objektinneren (Textur = gemeinsame Eigenschaft der GW-Verteilung einer Region) bestimmt
z.B.: 
- mittlerer GW
- GW-Varianz, Momente (Schiefe, Exzess)
- Haralick’sche Texturmaße
- Frequenzbereichsmerkmale, z.B. mittlere Amplitude in einem Bereich des Spektrums

Co-Occurrence-Matrix
- Berechnung der Wahrscheinlichkeit des Auftretens von Grauwertpaaren in definiertem Abstand/Richtung
- Hohe Werte auf der Diagonalen spiegeln geringe Grauwertdifferenzen benachbarter Pixel wider

Haralick‘sche Texturmaße
- Skalare Kenngrößen, die aus den normierten Co-Occurrence-Matrizen ermittelt werden
- je mehr Grauwerte (Grauwertpaare), desto kleiner der Wert
- Werte auf der Diagonalen spiegeln Homogenität in Richtung 𝛼𝛼 wider
- je größer die Grauwertdifferenz (Abweichung von der Diagonalen), desto kleiner der Quotient

## Formbasierte Merkmale
Merkmale werden vom Objektrand (Form) bestimmt
- Flächeninhalt des Segments
- Umfang des Segments
- Flächendifferenz zwischen Segment und seiner konvexen Hülle
- Kreisähnlichkeit
- Euler-Zahl $E=V-L$

## Einführung in die Klassifikation
- Bestimmung einer Abbildungsvorschrift, die einem Merkmalsvektor eine Klassennummer zuordnet
- Die Abbildungsvorschrift wird aus einem möglichst repräsentativen, vorklassifizierten Trainingsdatensatz bestimmt
- Annahme: Die Merkmale bilden verschiedene Objekte in getrennte, kompakte Bereiche im Merkmalsraum ab
- Minimum Distance Transformation
  - gegeben Traningsdatensätze
  - berechnung der zentrumsvektoren aller klassen 
  - graphische Darstellung -> Voronoi-Diagramm
- Weitere Klassifikatoren
  - Nearest Neighbor Klassifikation
  - Nearest k-Neighbor Klassifikation
  - Support-Vector Machines
  - Statistische Klassifikatoren
  - Neuronale Netze