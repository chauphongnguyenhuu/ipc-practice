TEMPLATE = subdirs

SUBDIRS += \
    core \
    guess \
    service

service.depends = core
