TEMPLATE = subdirs

SUBDIRS += \
    core \
    guess \
    sandbox \
    service

service.depends = core
guess.depends = core
sandbox.depends = core
