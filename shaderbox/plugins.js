//
// plugins config
//
// https://github.com/denehyg/reveal.js-menu
menu: {
    // Specifies which side of the presentation the menu will 
    // be shown. Use 'left' or 'right'.
    side: 'left',

    // Specifies the width of the menu.
    // Can be one of the following:
    // 'normal', 'wide', 'third', 'half', 'full', or
    // any valid css length value
    width: 'normal',

    // Add slide numbers to the titles in the slide list.
    // Use 'true' or format string (same as reveal.js slide numbers)
    numbers: true,

    // If slides do not have a matching title, attempt to use the
    // start of the text content as the title instead
    useTextContentForMissingTitles: true,

    // Hide slides from the menu that do not have a title.
    // Set to 'true' to only list slides with titles.
    hideMissingTitles: false,

    // Adds markers to the slide titles to indicate the 
    // progress through the presentation. Set to 'false'
    // to hide the markers.
    markers: true,

    // Specify custom panels to be included in the menu, by
    // providing an array of objects with 'title', 'icon'
    // properties, and either a 'src' or 'content' property.
    custom: false,

    // Specifies the themes that will be available in the themes
    // menu panel. Set to 'true' to show the themes menu panel
    // with the default themes list. Alternatively, provide an
    // array to specify the themes to make available in the
    // themes menu panel, for example...
    // [
    //     { name: 'Black', theme: 'css/theme/black.css' },
    //     { name: 'White', theme: 'css/theme/white.css' },
    //     { name: 'League', theme: 'css/theme/league.css' }
    // ]
    themes: true,

    // Specifies the path to the default theme files. If your
    // presentation uses a different path to the standard reveal
    // layout then you need to provide this option, but only
    // when 'themes' is set to 'true'. If you provide your own 
    // list of themes or 'themes' is set to 'false' the 
    // 'themesPath' option is ignored.
    themesPath: 'css/theme/',

    // Specifies if the transitions menu panel will be shown.
    // Set to 'true' to show the transitions menu panel with
    // the default transitions list. Alternatively, provide an
    // array to specify the transitions to make available in
    // the transitions panel, for example...
    // ['None', 'Fade', 'Slide']
    transitions: true,

    // Adds a menu button to the slides to open the menu panel.
    // Set to 'false' to hide the button.
    openButton: true,

    // If 'true' allows the slide number in the presentation to
    // open the menu panel. The reveal.js slideNumber option must 
    // be displayed for this to take effect
    openSlideNumber: false,

    // If true allows the user to open and navigate the menu using
    // the keyboard. Standard keyboard interaction with reveal
    // will be disabled while the menu is open.
    keyboard: true,

    // Normally the menu will close on user actions such as
    // selecting a menu item, or clicking the presentation area.
    // If 'true', the sticky option will leave the menu open
    // until it is explicitly closed, that is, using the close
    // button or pressing the ESC or m key (when the keyboard 
    // interaction option is enabled).
    sticky: false,

    // If 'true' standard menu items will be automatically opened
    // when navigating using the keyboard. Note: this only takes 
    // effect when both the 'keyboard' and 'sticky' options are enabled.
    autoOpen: true,

    // If 'true' the menu will not be created until it is explicitly
    // requested by calling RevealMenu.init(). Note this will delay
    // the creation of all menu panels, including custom panels, and
    // the menu button.
    delayInit: false,

    // If 'true' the menu will be shown when the menu is initialised.
    openOnInit: false,

    // By default the menu will load it's own font-awesome library
    // icons. If your presentation needs to load a different
    // font-awesome library the 'loadIcons' option can be set to false
    // and the menu will not attempt to load the font-awesome library.
    loadIcons: true
},
// https://github.com/tkrkt/reveal.js-elapsed-time-bar
allottedTime: 45 * 60 * 1000, // minutes
progressBarHeight: 5,
barColor: 'rgb(66, 175, 250)',

//
// plugins
//
dependencies: [
    { src: 'node_modules/reveal.js/plugin/elapsed-time-bar/elapsed-time-bar.js'}, // https://github.com/tkrkt/reveal.js-elapsed-time-bar
    { src: 'node_modules/reveal.js-menu/menu.js' } // https://github.com/denehyg/reveal.js-menu

    , // default plugins past this point; also add new-line
