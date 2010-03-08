//
//  BriefsUITestsAppDelegate.h
//  BriefsUITests
//
//  Created by Rob Rhyne on 3/7/10.
//  Copyright Digital Arch Design, 2009. See LICENSE file for details.
//

#import <UIKit/UIKit.h>
#import "BFSceneViewController.h"

@interface BriefsUITestsAppDelegate : NSObject <UIApplicationDelegate> 
{
    UIWindow *window;
    BFSceneViewController *controller;
}

@property (nonatomic, retain) IBOutlet	UIWindow				*window;
@property (nonatomic, retain)			BFSceneViewController	*controller;

@end

