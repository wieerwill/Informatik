# Einführung - Übersicht Bildverarbeitungsprozess

## Bildverarbeitung
Bildverarbeitung / Bildanalyse
- Wissenschaft von der algorithmischen Verarbeitung von Informationen in Bildern
- Ziel: Ableitung relevanter (nützlicher) Parameter
- Anwendung in nahezu allen Bereichen von Wissenschaft und Technik, Medizin und Alltag

Vorlesung BVM
- Grundlagen der Digitalen Bildverarbeitung
- Anwendungsfokus: Medizinische Bildverarbeitung

Anwendungsfelder digitaler Bildverarbeitung
- Medizinische Diagnostik und Therapie
    - Röntgen, CT, DSA, PET, SPECT, Ultraschall, MRI, fMRI, OCT
- Biolog. Bildgebung
    - Histologie, Mikroskopie, Zählung, Klassifikation u. Morphologie von Zellen, Bewegungsanalyse, Wachstum
- Forensik / Rechtsmedizin
    - Fingerabdruck, Gesichtserkennung
- Mensch-Maschine-Kommunikation / Robotik
    - Gestenerkennung, Zeichensprache, Orientierung im Raum
- Dokumentenverarbeitung
    - Automatische Texterkennung (OCR), Scannen, Archivieren, Fotografie
- Industrie / Materialforschung
    - Qualitätssicherung, automatisches Zählen, Komponentenerkennung
- Remote Sensing
    - Ernte, Wetter, Vermessung, Militär, Astronomie

Medizinische Bildverarbeitung
- Anwendungsfelder
    - Diagnose
    - Screening
    - OP-Planung
    - Bestrahlungsplanung
    - Ausbildung
- Eigenschaften
    - Große Komplexität / multimodal (verschiedene bildgebende Verfahren)
    - Variabilität der Objekte /individuelle Unterschiede
    - Große Bedeutung feinster Strukturen
    - Dreidimensionale / dynamische Bilddaten
    - Vergleichbarkeit mit Standardfällen
    - Hohe Robustheit notwendig

Modellgestützte Interpretation
- Bildinformationen
    - Modell- bzw. anwendungsspezifische Interpretation des Bildes
    - Bild nur unter Erwartungshaltung bzw. mit Hilfe eines Modells interpretierbar
    - Können verfälscht oder widersprüchlich sein
- Bildrestauration
    - ''Pin Cushion'' Verzerrung, ''Barrel'' Verzerrung
    - Verzerrung durch Bewegung (Restauration durch inverse Filterung)
    - Fokussierungsunschärfe
    - Verrauschtes Bild -> Gauß-Filter
    - ,,Salz und Pfeffer'' Rauschen -> Medianfilter
    - Kontraständerung
- Bildregistrierung
- Segmentierung
    - Schwellwertsegmentierung
    - Erkennung von Kreisen (Hough-Transformation)
- Merkmale und Klassifikation

## Vorlesungsinhalt
0. Einführung
    - Bildverarbeitungsprozess
1. Bildrepräsentation und Bildeigenschaften
    - Ortsbereich
    - Spektralbereich
    - Diskrete 2D-Faltung
2. Bildvorverarbeitung
    - Bildrestauration
    - Bildregistrierung
    - Bildverbesserung
3. Segmentierung
    - Pixel- bzw. histogrammbasierteSegmentierung
    - Regionen-basierte Segmentierung
    - Kantenbasierte Segmentierung
    - Wasserscheidentransformation
    - Modellbasierte Segmentierung
4. Morphologische Operationen
    - Morphologische Basisoperationen
    - Entfernen von Segmentierungsfehlern
    - Bestimmung von Formmerkmalen
5. Merkmalsextraktion und Klassifikation
    - RegionenbasierteMerkmale
    - Formbasierte Merkmale
    - Einführung in die Klassifikation

# Literaturempfehlungen
- Wilhelm Burger and MarkJ. Burge, ,,Digitale Bildverarbeitung – eine algorithmische Einführung mit Java'', Springer, 3. Auflage, 2015
- Klaus D. Tönnies, ,,Grundlagen der Bildverarbeitung'', Pearson Studium, 1. Auflage, 2005
- Heinz Handels, ,,Medizinische Bildverarbeitung'', Vieweg+Teubner, 2. Auflage, 2009
- Bernd Jähne, ,,Digitale Bildverarbeitung'', Springer, 6. Auflage, 2005
- Angelika Erhardt, ,,Einführung in die Digitale Bildverarbeitung'', Vieweg+Teubner, 1.Auflage, 2008
- Rafael C. Gonzales and Richard E. Woods, ,,Digital Image Processing'', Pearson International, 3. Edition,2008
- Geoff Dougherty, ,,Digital Image Processing for Medical Applications'', Cambridge University Press, 1. Edition, 2009
- William K. Pratt, ,,DigitalImageProcessing'', Wiley, 4. Edition, 2007
- John L. Semmlow, ,,Biosignal and Medical Image Processing'', CRCPress, 2. Edition, 2009