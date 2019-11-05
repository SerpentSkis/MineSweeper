#!/bin/sh
make -C /Users/chadhurst/repo/ChadBentley -f /Users/chadhurst/repo/ChadBentley/CMakeScripts/ZERO_CHECK_cmakeRulesBuildPhase.make$CONFIGURATION OBJDIR=$(basename "$OBJECT_FILE_DIR_normal") all
