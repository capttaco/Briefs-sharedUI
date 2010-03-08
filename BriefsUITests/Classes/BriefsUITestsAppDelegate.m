//
//  BriefsUITestsAppDelegate.m
//  BriefsUITests
//
//  Created by Rob Rhyne on 3/7/10.
//  Copyright Digital Arch Design, 2009. See LICENSE file for details.
//

#import "BriefsUITestsAppDelegate.h"
#import "BFPresentationDispatch.h"
#import "BFSceneManager.h"

@implementation BriefsUITestsAppDelegate

@synthesize window, controller;


- (void)applicationDidFinishLaunching:(UIApplication *)application 
{    
	// Hide the status bar
    [[UIApplication sharedApplication] setStatusBarHidden:YES animated:NO];
    
    // Load the brief into memory
    NSString *path = [[NSBundle mainBundle] pathForResource:@"test" ofType:@"brieflist"];
    BFSceneManager *manager = [[BFSceneManager alloc] initWithPathToDictionary:path];
    
    // Construct the view controller and
    // initialize the dispatch singleton
    self.controller = [[BFSceneViewController alloc] initWithSceneManager:manager];
    [[BFPresentationDispatch sharedBFPresentationDispatch] setViewController:self.controller]; 
    
    // add the brief view to the window
    [window addSubview:[controller view]];
    [window makeKeyAndVisible];
    
    // Cleanup
    [manager release];
}


- (void)dealloc 
{
    [controller release];
    [window release];
    [super dealloc];
}



@end
