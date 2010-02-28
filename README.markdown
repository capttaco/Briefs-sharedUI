Briefs-sharedUI
===============
This is part of the Briefs Framework. (<a href="http://twitter.com/briefsapp">@briefsapp</a> on Twitter)

When used in tandem with the [Briefs-data][1] project, one can create an iPhone app that can launch `.brieflist` files and respond to touch input.

[1]: "http://github.com/capttaco/Briefs-data"


How to Launch a Brief
---------------------
To launch a brief (called `abrief.brieflist` below) that is part of the app resources bundle, use the following code for the `applicationDidFinishLaunching:` method in your App Delegate:

    - (void)applicationDidFinishLaunching:(UIApplication *)application 
    {
        // Hide the status bar
        [[UIApplication sharedApplication] setStatusBarHidden:YES animated:NO];

        // Load the brief into memory
        NSString *path = [[NSBundle mainBundle] pathForResource:@"aBrief" ofType:@"brieflist"];
        BFSceneManager *manager = [[BFSceneManager alloc] initWithPathToDictionary:path];
        
        // Construct the view controller and
        // initialize the dispatch singleton
        BFSceneViewController *controller = [[BFSceneViewController alloc] initWithSceneManager:manager];
        [[BFPresentationDispatch sharedBFPresentationDispatch] setViewController:controller]; 

        // add the brief view to the window
        [window addSubview:[controller view]];
        [window makeKeyAndVisible];
        
        // Cleanup
        [manager release];
        [path release];

    }
    


Contact
-------

This framework is currently a work in progress. Please contact me with any questions about future status and feature requests.

<a href="mailto:rob@robrhyne.com">rob@robrhyne.com</a>