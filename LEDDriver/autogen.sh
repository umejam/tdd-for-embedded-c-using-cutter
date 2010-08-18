#!/bin/sh

run()
{
    $@
    if test $? -ne 0; then
        echo "Failed $@"
        exit 1
    fi
}

if [ ! -d src ]; then
    mkdir src
fi

if [ ! -d config ]; then
    mkdir config
fi

run aclocal ${ACLOCAL_ARGS}
run glibtoolize --copy --force
run autoheader
run automake --add-missing --foreign --copy
run autoconf
