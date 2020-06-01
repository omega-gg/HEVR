#!/bin/sh
set -e

includeGenerator="../../Sky/deploy/includeGenerator"

"$includeGenerator" ../../src/HEVR/src   HEVR
"$includeGenerator" ../../src/OpenVR/src OpenVR
