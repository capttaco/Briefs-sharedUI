//
//  BFPresentationController.h
//  Briefs
//
//  Created by Rob Rhyne on 8/4/09.
//  Copyright Digital Arch Design, 2009. See LICENSE file for details.
//

#import <Foundation/Foundation.h>
#import "BFDispatch.h"
#import "BFSceneViewController.h"

@interface BFPresentationDispatch : NSObject <BFLocalActionDispatch, BFGlobalActionDispatch>
{
    BFSceneViewController *__unsafe_unretained viewController;
}

@property (unsafe_unretained) BFSceneViewController *viewController;


// Singleton Accessors
+ (BFPresentationDispatch *) sharedBFPresentationDispatch;
+ (id<BFLocalActionDispatch>) sharedLocalDispatch;
+ (id<BFGlobalActionDispatch>) sharedGlobalDispatch;



@end
