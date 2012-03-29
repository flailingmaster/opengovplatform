
============================
 Views Slideshow: ImageFlow
============================

This module will display a view of images using the ImageFlow JavaScript plugin
available from http://finnrudolph.de/ImageFlow.

ImageFlow is a picture gallery, which allows an intuitive image handling. The
basic idea is to digitally animate the thumbing through a physical image stack.
That intuitive handling is automatically caused by the metaphorical use of the
well known process of thumbing through.

This solution is known as the Cover Flow technique, which has been developed by
the artist Andrew Coulter Enright. Now - after it has been bought by Apple - it
is used in iTunes and the file browser of Apples OSX.

==============
 Installation
==============

1. Extract the contents of the project into your modules directory, probably at
   /sites/all/modules/views_slideshow_imageflow.
2. Download the ImageFlow Javascript plugin from
   http://finnrudolph.de/ImageFlow/Download.
3. Extract the contents of that archive into /sites/all/plugins/imageflow.
   You may optionally install that to another folder, but will need to then
   specify the new location at /admin/build/views/views_slideshow_imageflow.
4. Create a new View with images, using 'Slideshow' for the 'Style', and
   'ImageFlow' for the 'Slideshow mode' when configuring the style.

=======
 Notes
=======

It's important to note that if you have anything besides images displayed in
your view, it will be filtered out of the display. This plugin will only
display images. However, it will respect any links the images point to, as
specified by your View. Other than that, it should work with any image fields
in your view, whether from the ImageField, Image, Embedded Media Field (using
thumbnails), or other similar modules.
