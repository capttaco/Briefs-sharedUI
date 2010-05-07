//
//  BFRootView.h
//  Briefs
//
//  Created by Rob Rhyne on 8/19/09.
//  Copyright Digital Arch Design, 2009. See LICENSE file for details.
//


@interface BFRootView : UIView
{
    UIViewController    *viewController;
    NSTimer             *timer;
}

- (id)initWithFrame:(CGRect)frame andViewController:(UIViewController *)controller;
- (void)cancelGestureTimer;


@end
