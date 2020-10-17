---
title: Rechnerarchitekturen 2
date: Wintersemester 20/21
author: Robert Jeutter
---

# Einführung
> Rechnerarchitektur = Programmierschnittstelle + Interner Aufbau
> Einheit von Struktur und Funktion

Abstraktionsebenen eines Rechnersystems
| Anwendungsprogramm | Java, C,... |
| Assemblerprogramm | Betriebssystem-Ebene |
| Maschinenprogramm | Betriebssystem-Ebene |
| Register Transfer Verhaltensebene | Reg[2]:=Reg[3] |
| Register Transfer Strukturebene | Addierer, Multiplexer, Register |
| Gatterebene | $f=a\vee bc$ |
| Transistorebene |  |

Grundarchitekturen:
- Harvard (Zugriff direkt durch Prozessor)
- Princton/von-Neumann (Zugriff über Systembus)

- Speicher, Steuerwerk: Daten und Instruktionen speichern; beinhaltet Programmzähler um Ausführung zu steuern
- Rechenwerk: auch ALU (Arithmetic and Logic Unit) um Berechnung durchzuführen
    - Daten aus Hauptspeicher in Register laden
    - Berechnungsaufgaben durchführen
    - Ergebnisse in Hauptspeicher ablegen

Programmiermodelle
- CISC - Complex Instruction Set Computers
- RISC - Reduced Instruction Set Computers
- MIPS - Microprozessor without interlocked pipeline stages

> Unter dem CPI (cycles per instruction) -Wert einer Menge von Maschinenbefehlen versteht man die mittlere Anszahl der Taktzyklen pro Maschinenbefehl


# Prozessorarchitektur


# Speicherarchitektur


# Microcontroller und Digitale Signalprozessoren


# Parallele Architekturen


# Leistungsbewertung
