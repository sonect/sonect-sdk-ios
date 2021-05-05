//
//  BorderedButton.swift
//  Sonect-iOS
//
//  Created by Marko Hlebar on 18/01/2019.
//  Copyright © 2019 Sonect. All rights reserved.
//

import UIKit
import QuartzCore

@IBDesignable class BorderedButton: UIButton {

    static func borderedButton(with frame: CGRect) -> BorderedButton {
        let button = BorderedButton(type:.custom)
        button.frame = frame
        button.layer.masksToBounds = true
        button.updateCornerRadius(with: button.bounds)
        return button
    }

    override func layoutSubviews() {
        super.layoutSubviews()

        updateCornerRadius(with: bounds)
    }

    //Don't move these to a UIView extension. Slows down compilation
    @IBInspectable
    var cornerRadius: CGFloat {
        get {
            return layer.cornerRadius
        }
        set {
            layer.cornerRadius = newValue
            layer.masksToBounds = newValue > 0
        }
    }

    @IBInspectable
    var borderWidth: CGFloat {
        get {
            return layer.borderWidth
        }
        set {
            layer.borderWidth = newValue
        }
    }

    @IBInspectable
    var borderColor: UIColor? {
        get {
            let color = UIColor(cgColor: layer.borderColor!)
            return color
        }
        set {
            layer.borderColor = newValue?.cgColor
        }
    }
}

fileprivate extension BorderedButton {

    func updateCornerRadius(with bounds:CGRect) {
        self.cornerRadius = bounds.size.height / 2
    }
}
