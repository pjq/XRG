/* 
 * XRG (X Resource Graph):  A system resource grapher for Mac OS X.
 * Copyright (C) 2002-2012 Gaucho Software, LLC.
 * You can view the complete license in the LICENSE file in the root
 * of the source tree.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 *
 */

//
//  XRGNetView.h
//

#import <Cocoa/Cocoa.h>
#import "definitions.h"
#import "XRGGenericView.h"

@interface XRGNetView : XRGGenericView {   
@private
    NSSize                  graphSize;
    int                     numSamples;
    XRGModule               *m;
    
    io_stats                i_net, o_net;
    network_interface_stats *interfaceStats;
    int                     pppInterfaceNum;
    int                     numInterfaces;
    int                     sendBytes;
    int                     recvBytes;
    UInt64                  totalBytesSinceBoot;
    UInt64                  totalBytesSinceLoad;
    int                     mib[6];
    char                    *buf;
    size_t                  alloc;


    int                     *rxValues;
    int                     *txValues;
    int                     *values;
    int                     currentIndex;
    int                     maxVal;
    
    bool                    firstTimeStats;
    NSMutableArray          *networkInterfaces;
}
- (void)setGraphSize:(NSSize)newSize;
- (void)setWidth:(int)newWidth;
- (void)updateMinSize;
- (int)convertHeight:(int) yComponent;
- (void)setCurrentBandwidth;
- (void)getInterfacesBandwidth;
- (void)setInterfaceBandwidth:(char *)interface_name inBytes:(UInt64)in_bytes outBytes:(UInt64)out_bytes;
- (void)graphUpdate:(NSTimer *)aTimer;
- (int)getSendBytes;
- (int)getRecvBytes;
- (int)getMaxValue;
- (void)setNetworkInterfaces:(char **)interfaces;
- (NSArray *)networkInterfaces;
@end
