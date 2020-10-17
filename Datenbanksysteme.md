---
title: Datenbanksysteme
date: Wintersemester 20/21
author: Robert Jeutter
---

# Was sind Datenbanken - Grundlegende Konzepte
## Überblick
- Daten = logisch gruppierte Informationseinheiten
- Bank = Sicherheit vor Verlust, Dienstleistung für mehrere Kunden, (langfristige) Aufbewahrung

Ohne Datenbanken:
- jedes Anwendungssystem verwaltet seine eigenen Daten
- Daten sind (redundant) mehrfach gespeichert
- Probleme
  - Verschwenden von Speicherplatz
  - "vergessen" von Änderungen
  - keine zentrale "genormte" Datenerhaltung
- größere Mengen von Daten nicht effizient verarbeitet
- mehrere Benutzer können nicht parallel auf den gleichen Daten arbeiten, ohne sich zu stören
- Anwendungsprogrammierer/Benutzer können Anwendungen nicht programmieren/benutzen ohne ... zu kennen (keine Datenunabhängigkeit)
  - interne Dartstellung der Daten
  - Speichermedien oder Rechner
- Datenschutz und   Datensicherheit

### Datenintegration durch Datenbanksystem
Anwendungen greifen über Datenbankmanagementsystem auf Datenbank zu.

Datenbankmanagementsystem (DBMS): Software zur Verwaltung von Datenbanken

Datenbank (DB): strukturierter, von DBMS verwalteter Datenbestand

Datenbanksystem (DBS) = DBMS + DB



## Architekturen
die neun Codd'schen Regeln
1. Integration: einheitliche, nichtredundante Datenverwaltung
2. Operationen: Speichern, Suchen, Ändern
3. Katalog: Zugriffe auf Datenbankbeschreibungen im Data Dictionary
4. Benutzersichten
5. Integritätssicherung: Korrektheit des Datenbankinhalts
6. Datenschutz: Ausschluss unauthorisierter Zugriffe
7. Transaktionen: mehrere DB-Operationen als Funktionseinheit
8. Synchronisation: parallele Transaktionen koordinieren
9. Datensicherung: Wiederherstellung von Daten nach Systemfehlern

## Einsatzgebiete

## Historisches

# Relationale Datenbanken - Daten als Tabellen


# Datenbankentwurf im ER-Modell


# Relationaler DB-Entwurf


# Relationale Entwurfstheorie


# die Datenbanksprache SQL


# Grundlagen von Anfragen: Algebra & Kalkül


# Transaktionen, Integrität und Trigger


# Sichten und Zugriffskontrolle


# NoSQL Datenbanken